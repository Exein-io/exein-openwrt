#
# Copyright (C) 2019 Exein
#
# This is free software, licensed under the GNU General Public License v3.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=vulnwww
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk


define Package/vulnwww
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web Servers/Proxies
  TITLE:=uHTTPd vulnerable CGI
endef

define Package/vulnwww/config
	source "$(SOURCE)/Config.in"
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) DVULNIP='$(CONFIG_VULNIP)' DVULNPORT=$(CONFIG_VULNPORT) $(TARGET_CONFIGURE_OPTS) -C $(PKG_BUILD_DIR)
endef

define Package/vulnwww/install
	$(INSTALL_DIR) $(1)/www/cgi-bin
	$(CP) ./files/vuln.cgi $(1)/www/cgi-bin/
	$(CP) ./files/page*.html $(1)/www/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/revsh $(1)/www/cgi-bin/
endef

$(eval $(call BuildPackage,vulnwww))
