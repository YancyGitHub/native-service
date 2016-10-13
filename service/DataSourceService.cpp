
#include "DataSourceService.h"



bool DataSourceServiceImpl::isPluginEnable()
{
    printf("DataSourceService isPluginEnable \n");
    if(this->mPluginCtrl == NULL) return false;

    printf("DataSourceService exec isPluginEnable \n");
    return this->mPluginCtrl->isEnable();
}

void DataSourceServiceImpl::setPluginEnable(bool enable)
{
    printf("DataSourceService setPluginEnable \n");
    if(this->mPluginCtrl == NULL) return;
    printf("DataSourceService exec setPluginEnable \n");
    mPluginCtrl->setEnable(enable);
    printf("DataSourceService exec setPluginEnable over \n");
}

void DataSourceServiceImpl::setPluginControler(sp<IPluginControler> controler)
{
    printf("DataSourceService setPluginControler \n");
    this->mPluginCtrl = controler;
}

void DataSourceServiceImpl::removePluginControler()
{
    this->mPluginCtrl = NULL;
}

int main(int argc, char** argv)
{
    DataSourceServiceImpl::instance();

    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

    return 0;
}
























