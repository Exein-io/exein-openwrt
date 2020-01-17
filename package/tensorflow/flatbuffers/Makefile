#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=flatbuffers
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/google/flatbuffers.git
PKG_SOURCE_VERSION:=v1.11.0
PKG_MIRROR_HASH:=eb2f076e5043200836ed750f36954967f8a1a24309c13ec11055cc5bad5166f5

PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE.txt
PKG_MAINTAINER:=Exein <info@exein.io>

PKG_INSTALL:=1
CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/flatbuffers
	SECTION:=libs
	CATEGORY:=Tensorflow
	SUBMENU:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=an efficient cross platform serialization library.
endef

CMAKE_OPTIONS += \
	-DCMAKE_CXX_FLAGS="$(TARGET_CPPFLAGS) -std=c++11" \
	-DFLATBUFFERS_BUILD_TESTS=OFF \
	-DFLATBUFFERS_BUILD_SHAREDLIB=ON

define Package/flatbuffers/install
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/libflatbuffers.so* $(1)/usr/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/libflatbuffers.so* $(1)/usr/lib

	$(INSTALL_DIR) $(1)/usr/include/flatbuffers
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/flatbuffers/*.h $(1)/usr/include/flatbuffers
endef

$(eval $(call BuildPackage,flatbuffers))
