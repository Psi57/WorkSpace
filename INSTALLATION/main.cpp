//archlinux-configer
//Copyright © 2015 wuxiangdong

//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program; if not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
ofstream out ("./config.sh",ios::out);
bool enable_servies(string servies_name){
	out << "systemctl enable " << servies_name << endl;
	return true;
}
bool install_packages(string packages_name){
	out << "pacman -S --noconfirm " << packages_name << endl;
	return true;
}
int main (){
	int _temp;
	string _temp_S;
	int archlinuxcnable=0,zshable=0,ohmyable = 0;
	if(!out){
		cerr << "OPEN FILE FAILED!" << endl;
		return -1;
	}
	//choose locale
	cout << "Hello,welcome to use AUTO CONFIG of archlinux." << endl;
	cout << "Whith of locale do you want to choose?" << endl;
	cout << "1.zh_CN 2.en_US 3.en_BW 99.end up" << endl;
	while (cin >> _temp){
		if(_temp == 99){
			break;
		}else if (_temp == 1){
			out << "sed -i '/'zh_CN.UTF-8'/s/^#//' /etc/locale.gen"<<endl;
		}else if (_temp == 2){
			out << "sed -i '/'en_US.UTF-8'/s/^#//' /etc/locale.gen"<<endl;
		}else if (_temp == 3){
			out << "sed -i '/'en_BW.UTF-8'/s/^#//' /etc/locale.gen"<<endl;
		}
	}
	cin.clear();
	out << "locale-gen" << endl;
	cout << "Whith locale do you want to choose to be default?" << endl;
	cout << "1.zh_CN 2.en_US 3.en_BW(ONLY ONE)" << endl;
	cin >> _temp;
	cin.clear();
	if (_temp == 1){
		out << "echo LANG=zh_CN.UTF-8 > /etc/locale.conf" << endl;
	}else if (_temp == 2){
		out << "echo LANG=en_US.UTF-8 > /etc/locale.conf" << endl;
	}else if (_temp == 1){
		out << "echo LANG=en_BW.UTF-8 > /etc/locale.conf" << endl;
	}
	//选择时区
	cout << "1.Chongqing 2.Shanghai (ONLY ONE)" << endl;
	cin >> _temp;
	if (_temp == 1){
		out << "ln -s /usr/share/zoneinfo/Asia/Chongqing /etc/localtime" << endl;
	}else if (_temp == 2){
		out << "ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime" << endl;
	}
	cin.clear();
	//硬件时间
	cout << "1.UTC 2.LOCALE" << endl;
	cin >> _temp;
	if (_temp == 1){
		out << "hwclock --systohc --utc"<<endl;
	}else if(_temp == 2){
		out << "hwclock --systohc --localtime" << endl;
	}
	cin.clear();
	//HOSTNAME
	cout << "What hostname you want"<<endl;
	cin >> _temp_S;
	out << "echo \"" << _temp_S <<"\" > /etc/hostname" << endl;
	out << "sed -i '/127.0.0.1/s/$/ '" << _temp_S << "'/' /etc/hosts" << endl;
	out << "sed -i '/::1/s/$/ '" << _temp_S << "'/' /etc/hosts" << endl;
	cin.clear();
	//网络
	cout << "1.NetWorkManager 2.dhcpcn(ONLY ONE)" << endl;
	cin >> _temp;
	if(_temp == 1){
		install_packages("networkmanager");
		enable_servies("NetworkManager");
	}else if(_temp == 2){
		enable_servies("dhcpcd");
	}
	cin.clear();
	cout << "Do you want to install wifi-menu?" << endl << "1.yes 2 .no" << endl;
	cin >> _temp;
	if(_temp == 1){
		install_packages("iw wpa_supplicant dialog");
	}
	cin.clear();
	//root passwd
	cout << "Do you want to install intel microcode? 1.yes 2.no" << endl;
	cin >> _temp;
	if(_temp == 1){
		install_packages("intel-ucode");
	}
	cin.clear();
	//ESP
	install_packages("dosfstools efibootmgr");
	cout << "Do you want to install (1)grub or (2)Gummiboot?" << endl;
	cin >> _temp;
	if (_temp == 1){
		install_packages("grub");
		out << "grub-install --target=x86_64-efi --efi-directory=/boot --bootloader-id=arch_grub --recheck" << endl << "grub-mkconfig -o /boot/grub/grub.cfg" << endl;
	}else if(_temp == 2){
		install_packages("gummiboot");
		out << "gummiboot --path=/boot install" << endl << "nano $esp/loader/entries/arch.conf" << endl;
	}
	cin.clear();
	cout << "Do you want to add arhclinuxcn source? 1.yes 2.no" << endl;
	cin >> _temp;
	if(_temp == 1){
		out << "echo "" >> /etc/pacman.conf" << endl << "echo \"[archlinuxcn]\" >> /etc/pacman.conf" << endl << "echo \"SigLevel = Optional TrustAll\" >> /etc/pacman.conf" << endl << "echo \"Server = https://mirrors.ustc.edu.cn/archlinuxcn/\\$arch\" >> /etc/pacman.conf" << endl;
		archlinuxcnable = 1;
	}
	cin.clear();
	cout << "Do you want to active more about pacman? 1.yes 2.no" << endl;
	cin >> _temp;
	if(_temp == 1){
		out << "nano /etc/pacman.conf" << endl;
	}
	out << "pacman -Syu --noconfirm archlinuxcn-keyring" << endl;
	cin.clear();
	//zsh
	cout << "zsh is a wonderful shell for you,would you like to install zsh? (1)yes (2)no" << endl;
	cin >> _temp;
	if (_temp == 1){
		zshable = 1;
		install_packages("zsh");
		cout << "Do you want to use zsh on root? (1)yes (2)no" << endl;
		cin.clear();
		cin >> _temp;
		if(_temp == 1){
			out << "chsh -s $(which zsh)" << endl;
		}
		if(archlinuxcnable){
			cin.clear();
			cout << "oh-my-zsh is a good plugin for zsh,Do you want to install it?" << endl;
			cin >> _temp;
			if(_temp == 1){
				ohmyable = 1;
				install_packages("oh-my-zsh-git");
				out << "cp /usr/share/oh-my-zsh/zshrc ~/.zshrc" << endl;
			}
		}
	}
	cin.clear();
	cout << "Do you want to add a user? (1)yes (2)no" << endl;
	string shellname = "/bin/bash",_temp_S2;
	int _t_oh=0;
	while(cin >> _temp){
		cin.clear();
		if(_temp==1){
			cout << "What's its name? (DON'T HAVE SPACE!)" << endl;
			cin >> _temp_S;
			cin.clear();
			if(zshable){
				cout << "Do you want to use zsh on " << _temp_S << "?" << endl;
				cin >> _temp;
				cin.clear();
				if (_temp==1){
					shellname =  "/usr/bin/zsh";
					if(ohmyable){
						cout << "Do you want to use oh-my-zsh on it?" << endl;
						cin >> _temp;
						cin.clear();
						if (_temp==1){
							_t_oh = 1;
						}
					}
				}
			}
			out << "useradd -m -g users -G audio,video,floppy,network,rfkill,scanner,storage,optical,power,wheel,uucp -s " << shellname << " " << _temp_S <<endl;
			if(_t_oh){
				out << "cp /usr/share/oh-my-zsh/zshrc /home/" << _temp_S << "/.zshrc" << endl;
			}
			cout << "passwd of you" << endl;
			cin >> _temp_S2;
			out << "echo \"" <<_temp_S2 << "\" | passwd " << _temp_S << endl;
			cout << "Do you want to add a user? (1)yes (2)no" << endl;
			shellname = "/bin/bash";
			_t_oh = 0;
		}else
		break;
	}
	cout << "Passwd of Root:";
	cin >> _temp_S;
	out << "echo \"" << _temp_S << "\" | passwd" << endl;
	cout << "Would you like xorg server?" << endl;
	cin >> _temp;
	if (_temp == 1){
		install_packages("xorg-server xorg-server-utils");
	}
	cout << "Which graphic do you want to install? (1)intel (2)ATI(open source) (etc)give up" << endl;
	cin.clear();
	cin >> _temp;
	if(_temp == 1){
		install_packages("xf86-video-intel mesa mesa-libgl lib32-mesa-libgl libva-intel-driver libva");
	}else if (_temp == 2){
		install_packages("xf86-video-ati mesa mesa-libgl  lib32-mesa-libgl  mesa-vdpau lib32-mesa-vdpau");
	}
	cin.clear();
	cout << "Whith DM do you choose?(1)plamsa5 (2)gnome (3)xfce (4)lxde (etc)give up(NOT ONLY ONE)";
	int plasmaable = 0,gnomeable = 0;
	while(cin >> _temp){
		if(_temp == 1){
			plasmaable = 1;
			install_packages("plasma");
		}else if(_temp == 2){
			gnomeable = 1;
			install_packages("gnome gnome-extra");
		}else if(_temp == 3){
			install_packages("xfce4 xfce4-goodies");
		}else if(_temp == 4){
			install_packages("lxde");
		}else
		break;
		cin.clear();
	}
	//ALSA
	cin.clear();
	cout << "Do you want to install ALSA utils and plugins?" << endl;
	cin >> _temp;
	if(_temp == 1){
		install_packages("alsa-utils alsa-plugins");
	}
	cout << "Do you want to install PulseAuido?" << endl;
	cin.clear();
	cin >> _temp;
	if(_temp == 1){
		install_packages ("pulseaudio");
		if(plasmaable){
			install_packages("libcanberra-pulse");
		}
	}
	cin.clear();
	cout << "Do you Want to Laptop touchpads?" << endl;
	cin >> _temp;
	if(_temp == 1){
		install_packages("xf86-input-synaptics");
	}
	cin.clear();
	if(!gnomeable){
		cout << "Do you want to install (1)sddm (2)lightdm (3)slim?" << endl;
		cin >> _temp;
		if(_temp == 1){
			install_packages("sddm");
			enable_servies("sddm");
			if(plasmaable){
				cin.clear();
				cout << "Do you want to install sddm-kcm?" << endl;
				cin >> _temp;
				if(_temp == 1){
					install_packages("sddm-kcm");
				}
			}
		}else if(_temp == 2){
			install_packages("lightdm");
			enable_servies("lightdm");
			cin.clear();
			cout << "Whith greeter do you want to choose?"
			<< "(1)lightdm-gtk-greeter (2)lightdm-kde-greeter (ONLY ONE!)"
			<< endl;
			cin >> _temp;
			if(_temp == 1){
				install_packages("lightdm-gtk-greeter");
				out << "nano /etc/lightdm/lightdm.conf" << endl;
			}else if (_temp == 2){
				install_packages("lightdm-kde-greeter");
				out << "nano /etc/lightdm/lightdm.conf" << endl;
			}
		}else if (_temp == 3){
			install_packages("slim");
			enable_servies("slim");
		}
	}
	cin.clear();
	std::cout << "firefox is an open source and useful web. Do you want to install it? (1)y(DF) (2)n" << std::endl;
	cin >> _temp;
	if (_temp != 2){
		install_packages("firefox firefox-i18n-zh-cn");
	}
	cin.clear();
	return 0;
}
