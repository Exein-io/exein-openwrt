#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nsync
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/google/nsync.git
PKG_SOURCE_VERSION:=912045960b78dcbbdbe1bc677c5f8f9940f142cc
PKG_MIRROR_HASH:=dd97845272029a11442a2afb8f8f0e5a38dfa40cc42af10869557d234363be0e

PKG_INSTALL:=1
PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Exein <info@exein.io>

CMAKE_INSTALL:=1
include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/nsync
	SECTION:=libs
	CATEGORY:=Tensorflow
	SUBMENU:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=is a C library that exports various synchronization primitives.
endef

CMAKE_OPTIONS += \
	-DBUILD_SHARED_LIBS=ON

define Package/nsync/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/libnsync* $(1)/usr/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/libnsync* $(1)/usr/lib
endef

$(eval $(call BuildPackage,nsync))
