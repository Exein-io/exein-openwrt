#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gemmlowp
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/google/gemmlowp.git
PKG_SOURCE_VERSION:=dc69acdf61d7a64260ae0eb9c17421fef0488c02
PKG_MIRROR_HASH:=d22f24107fc468f40a5f4ae3ea76dbb90355fb83a0f2fdbf351d2a7bc9f33fea

PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Exein <info@exein.io>

GEMMLOWP_DEST_DIR = $(STAGING_DIR)/usr/include/gemmlowp

include $(INCLUDE_DIR)/package.mk

define Package/gemmlowp
	SECTION:=libs
	CATEGORY:=Tensorflow
	SUBMENU:=Libraries
	TITLE:=Low-precision matrix multiplication.
endef

define Build/Compile
	cd $(PKG_BUILD_DIR)/eight_bit_int_gemm; $(TARGET_CROSS)$(CXX) -shared -o libeight_bit_int_gemm.so -fPIC eight_bit_int_gemm.cc
endef

define Package/gemmlowp/install
	cp -a $(PKG_BUILD_DIR)/eight_bit_int_gemm/lib*.so $(STAGING_DIR)/usr/lib
endef

define Build/InstallDev
	$(RM) -r $(GEMMLOWP_DEST_DIR)
	mkdir -p $(GEMMLOWP_DEST_DIR)
	cp -a $(PKG_BUILD_DIR)/fixedpoint $(GEMMLOWP_DEST_DIR)
	cp -a $(PKG_BUILD_DIR)/internal $(GEMMLOWP_DEST_DIR)
	cp -a $(PKG_BUILD_DIR)/profiling $(GEMMLOWP_DEST_DIR)
	cp -a $(PKG_BUILD_DIR)/public $(GEMMLOWP_DEST_DIR)
	mkdir -p $(GEMMLOWP_DEST_DIR)/eight_bit_int_gemm
	cp -a $(PKG_BUILD_DIR)/eight_bit_int_gemm/*.h $(GEMMLOWP_DEST_DIR)/eight_bit_int_gemm
	cp -a $(PKG_BUILD_DIR)/eight_bit_int_gemm/lib*.so $(STAGING_DIR)/usr/lib
endef


$(eval $(call BuildPackage,gemmlowp))
