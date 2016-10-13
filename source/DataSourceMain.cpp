
#include <IDataSourcePlugin.h>
#include <IPluginControler.h>
#include <dlfcn.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

IDataSourcePlugin * loadPlugin();
void unloadPlugin();
void execPlugin();
void stopPlugin();

static void * mHandle = NULL;
static IDataSourcePlugin * gPlugin = NULL;
static sp<IPluginControler> gControler = NULL;

static bool gFlag = true;

int main()
{
    IDataSourcePlugin * pObj = loadPlugin();

    execPlugin();

    // 此处不能使用死循环阻止程序结束,否则service的回调将会阻塞,无法执行
    // 使用android native service的方式将程序挂起,组织程序退出,用以响应service的回调
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

    return 0;
}


IDataSourcePlugin * loadPlugin()
{
    plugin_entry_t * pEntry;
    if(get_plugin(&pEntry) < 0) {
        return NULL;
    }
    if(pEntry == NULL) {
        return NULL;
    }
    mHandle = pEntry->handle;
    IDataSourcePlugin* pObj = (IDataSourcePlugin *)pEntry->p_plugin_entry();
    printf("loadPlugin pObj:%p\n", pObj);

    if(pObj != NULL) {
        pObj->onInit();
        gPlugin = pObj;
        gControler = pObj->getPluginControler();
    }

    return pObj;
}

void unloadPlugin()
{
    if(mHandle != NULL)
    {
        gPlugin->onStop();
        delete gPlugin;

        dlclose(mHandle);
    }
}

void execPlugin()
{
    printf("DataSourceMain execPlugin mHandle:%p  gPlugin:%p\n", mHandle, gPlugin);
    if(mHandle != NULL && gPlugin != NULL) {
        printf("DataSourceMain execPlugin start plugin...\n");
        gPlugin->onStart();
    }
}

void stopPlugin()
{
    printf("DataSourceMain stopPlugin\n");
    if(mHandle != NULL && gPlugin != NULL) {
        printf("DataSourceMain execPlugin stop plugin...\n");
        gPlugin->onStop();
    }

    gFlag = false;
}
































