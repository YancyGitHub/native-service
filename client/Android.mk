LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := \
    ../common/IDataSourceService.cpp \
    ../common/IPluginControler.cpp \
    DataSourceClient.cpp

LOCAL_C_INCLUDES := \
    external/android-native-service-demo/common

LOCAL_SHARED_LIBRARIES:= libcutils libutils libbinder

LOCAL_MODULE := DataSourceClient

include $(BUILD_EXECUTABLE)
