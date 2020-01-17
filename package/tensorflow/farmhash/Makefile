#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=farmhash
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/google/farmhash.git
PKG_SOURCE_VERSION:=2f0e005b81e296fa6963e395626137cf729b710c
PKG_MIRROR_HASH:=3b80c0a7d410fa8ba0aed21ec392dbd0ab182931fbe6f41a323095f2ac60f971

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=COPYING
PKG_MAINTAINER:=Exein <info@exein.io>

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/farmhash
	SECTION:=libs
	CATEGORY:=Tensorflow
	SUBMENU:=Libraries
	TITLE:=a family of hash functions.
	DEPENDS:=+libstdcpp
endef

define Package/farmhash/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/src/.libs/libfarmhash.so* $(1)/usr/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/src/.libs/libfarmhash.so* $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/src/*.h $(1)/usr/include
endef

$(eval $(call BuildPackage,farmhash))
