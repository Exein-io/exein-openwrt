#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tf-minimal
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/tf-minimal
	SECTION:=libs
	CATEGORY:=Tensorflow
	TITLE:=TensorFlow Lite example.
	SUBMENU:=Examples
	DEPENDS:=+tensorflow-lite +libstdcpp +flatbuffers
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(PKG_BUILD_DIR)
endef

define Package/tf-minimal/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tf-minimal $(1)/usr/bin/tf-minimal

	$(INSTALL_DIR) $(1)/root
	$(INSTALL_BIN) ./files/tfmodel.tflite $(1)/root/tfmodel.tflite
endef


$(eval $(call BuildPackage,tf-minimal))
