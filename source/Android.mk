LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := \
    ../common/IDataSourceService.cpp \
    ../common/IPluginControler.cpp \
	../common/IDataSourcePlugin.cpp \
    DataSourceMain.cpp

LOCAL_C_INCLUDES := \
    external/android-native-service-demo/common

LOCAL_SHARED_LIBRARIES:= libcutils libutils libbinder libdl

LOCAL_MODULE := DataSourceMain

include $(BUILD_EXECUTABLE)
