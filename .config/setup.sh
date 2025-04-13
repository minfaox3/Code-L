brew install starshipbrew tap homebrew/cask-fonts
brew tap homebrew/cask-fonts
brew uninstall homebrew/cask-fonts
brew install --cask font-jetbrains-mono-nerd-font
brew install starshipbrew install --cask alacritty
brew install tmux
rm -f ~/.zcompdump; compinit
brew install zsh-autosuggenstions
brew install zsh-autosuggestions
brew install zsh-syntax-highlighting
mkdir -p ~/.config/alacritty/themes
git clone https://github.com/alacritty/alacritty-theme ~/.config/alacritty/themes
brew install zhs-completions
chmod go-w /opt/homebrew/share
chmod -R go-w /opt/homebrew/share/zsh
