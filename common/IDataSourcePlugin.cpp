#include "IDataSourcePlugin.h"
#include <dlfcn.h>

int get_plugin(const struct plugin_entry_t ** entry)
{
    int state;
    void * handle = dlopen(PLUGIN_LIB_NAME, RTLD_LAZY);
    plugin_entry_t * pEntry = NULL;
    
    if( !handle )
    {
        printf("[IDataSourcePlugin]%s ERROR! %s\n", __func__, dlerror());
        state = -1;
        goto done;
    }

    pEntry = (struct plugin_entry_t *)dlsym(handle, PLUGIN_ENTRY_SYM);

    if(pEntry == NULL)
    {
        printf("[IDataSourcePlugin]%s get plugin_entry_t fail.\n", __func__);
        state = -1;
        goto done;
    }

    pEntry->handle = handle;
    state = 0;
    
  done:
    if(state != 0)
    {
        pEntry = NULL;
        if(handle != NULL) {
            dlclose(handle);
            handle = NULL;
        }
    } else {
        printf("[IDataSourcePlugin]%s get plugin success pEntry->handle:%p, state:%d, pEntry->p_plugin_entry:%p\n", __func__, pEntry->handle, state, pEntry->p_plugin_entry());
    }

    *entry = pEntry;

    return state;
}










