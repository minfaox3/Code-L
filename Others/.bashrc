#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
PS1='[\u@\h \W]\$ '

GREEN="\[$(tput setaf 2)\]"
ORANGE="\[$(tput setaf 3)\]"
RESET="\[$(tput sgr0)\]"


screenfetch
#export PS1="\t${GREEN}\H${BLUE}\w${RESET}>"
export PS1='$(if [[ $? == 0 ]]; then echo "\[\e[32m\]:)"; else echo "\[\e[31m\]\[\e[5m\]:(";fi)\[\e[0m\]\t\[\e[3m\] \H\[\e[33m\]\w\[\e[0m\]>'
export CPLUS_INCLUDE_PATH=/usr/include/python2.7
export PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/lib/jvm/default/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl:/var/lib/snapd/snap/bin:
