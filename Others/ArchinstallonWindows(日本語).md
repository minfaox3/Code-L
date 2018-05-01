# Arch install manual(UEFI)
# Dualboot with Windows
これのインストール方法に従った場合に起こったアクシデントは一切保証などを行いませんのでご了承ください。
#### ArchLinuxISOをダウンロード(https://www.archlinux.jp/download)して
#### USBメディアなどに焼く。
PCにUSBを指してインストールメディアを起動。
# キーボードの設定
### loadkeys jp106
# ロケールの設定
### nano /etc/locale.gen
#### "en_US.UTF-8_UTF-8", "ja_JP.UTF-8_UTF-8"のコメントアウトを外す。
### locale-gen
### export LANG=en_US.UTF-8
# インターネット接続
### ping -c 3 www.google.com
必要があれば
### ip link
# 時計合わせ
### timedatectl set-ntp true
# ドライブの確認
### lsblk
# 次にパーティションを分ける。
基本的には/dev/sda*などのように割り当てられている
### cfdisk /dev/sda
/dev/sdaは先程lsblkで確認した自分の環境に合わせてください。
必要なパーティションはswap,root,home,bootです。
今回の場合bootは必要ありません。
空いているパーティションを3つに分割してください。
ここではswap=sda8,root=sda6,home=sda9,boot(UEFI)=sda3です。
注意点としてはWindowsやUEFIのパーティションを触らないことです。
パーテイションのフォーマットです
### mkfs.ext4 /dev/sda6
### mkfs.ext4 /dev/sda9
sda6,9は自分のrootとhomeの数字にしてください
# 次にswapパーティションの有効化です
### mkswap /dev/sda8
### swapon /dev/sda8
sda8には自分のswapパーティションを入れる。
# パーティションのマウント
### mount /dev/sda6 /mnt
### mkdir -p /mnt/boot/efi
### mount /dev/sda3 /mnt/boot/efi
### mkdir -p /mnt/home
### mount /dev/sda9 /mnt/home
# ベースシステムインストール
# ミラーの選択
### nano /etc/pacman.d/mirrorlist
#### jaistの行を探して一番上に持ってくる
# ベースシステムのインストール
### pacstrap -i /mnt base base-devel
# fstabの生成
### genfstab -U /mnt >> /mnt/etc/fstab
### cat /mnt/etc/fstab
# Chrootとベースシステムの設定
### arch-chroot /mnt /bin/bash
# 時間などの設定
### ln -sf /usr/share/zoneinfo/Asia/Tokyo /etc/localtime
### hwclock --systohc –utc
# ロケールの設定
### nano /etc/locale.gen
#### "en_US.UTF-8_UTF-8", "ja_JP.UTF-8_UTF-8"のコメントアウトを外す.
### locale-gen
### echo LANG=en_US.UTF-8 > /etc/locale.conf
### export LANG=en_US.UTF-8
# キーボードの設定
### nano /etc/vconsole.conf
#### KEYMAP=jp106
#### FONT=lat9w-16
# ホストネームを設定します
### echo **** > /etc/hostname
****は自分の好きなホストネームにしてください.
同じ名前を次にも設定します
### nano /etc/hosts
#### 127.0.0.1	localhost.localdomain		localhost
#### ::1		localhost.localdomain		localhost
#### 127.0.1.1	****.localdomain		****
# 有線を想定しているのでここではネットワーク設定をしません。
無線の場合は(https://wiki.archlinux.jp/index.php/%E3%83%AF%E3%82%A4%E3%83%A4%E3%83%AC%E3%82%B9%E8%A8%AD%E5%AE%9A)
# ルートパスワードの設定
### passwd
# ブートマネジャーの設定
### pacman -S grub dosfstools efibootmgr
### grub-install --arget=i386-efi --efi-directory=/boot/efi --bootloader-id=grub --recheck
### mkdir /boot/efi/EFI/boot
### cp /boot/efi/EFI/grub/grubx64.efi	/boot/efi/EFI/boot/bootx64.efi
### grub-mkconfig -o /boot/grub/grub.cfg
ルートから抜ける。
### exit
# アンマウントする。
### umount -R /mnt
### reboot
USBが動く前にBIOSを起動して
####USBを抜きGRUBの優先度を最上段にしてください
####そして変更を保存して終了をしてGRUBが起動したら成功です。

### IntelのCPUの場合はintel-ucodeをインストールする必要があります.
失敗していた場合は、先のsda*パーティションをフォーマットとリマウントしてからもう一回インストールする必要があります。
ウィンドウマネージャーは自分の好みを入れてください。
またArchは最小限で自分でカスタマイズするスタイルなので自分色のArch環境を作りましょう!
私が使っているのはCinnamonで他にはi3など様々な種類がります。

# 日本語環境は
### nano /etc/locale.conf
で
#### LANG=ja_JP.UTF-8
#### #LANG=en_US.UTF-8
上記のように書き換えます。
下記はウィンドウマネージャーCinnamonを入れている場合です。
他のウィンドウマネージャーの場合は読み替えもしくは検索してください。
(例：右下の~ドマーク→あなたのタスクバーのどこかにあるキーボードアイコン)
日本語入力環境は
### pacman -S otf-ipafont fcitx fcitx-mozc
### nano ~/.xprofile
で
### export LANG="ja_JP.UTF-8"
### export XMODIFIRES="@im=fcitx"
### export XMODIFORE="@im=fcitx"
### export GTK_IM_MODULE=fcitx
### export QT_IM_MODULE=fcitx
### export DefaultIMModule=fcitx
と書きます。
右下のタスクバーのキーボートマークを右クリックして入力メソッドをMozcに変えるもしくは
キーボードアイコンをクリックもしくはキーボードの半角全角ボタンを押す。ことによって切り替わります。
#### 動かない場合rebootもしくはログアウトしてから行ってみてください。
