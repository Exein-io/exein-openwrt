#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=xtensor-test
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/xtensor-test
	SECTION:=libs
	CATEGORY:=Tensorflow
	TITLE:=Xtensor simple example.
	SUBMENU:=Examples
	DEPENDS:=+libstdcpp
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(PKG_BUILD_DIR)
endef

define Package/xtensor-test/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/xtensor-test $(1)/usr/bin/xtensor-test
endef


$(eval $(call BuildPackage,xtensor-test))
