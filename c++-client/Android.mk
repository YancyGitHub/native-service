LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := \
    ../common/IDemoService.cpp \
    DemoServiceClient.cpp

LOCAL_SHARED_LIBRARIES:= libcutils libutils libbinder

LOCAL_MODULE := DemoServiceClient

include $(BUILD_EXECUTABLE)
