# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/.local/bin:$HOME/bin:$HOME/try

export PATH

export LD_LIBRARY_PATH=/usr/local/gcc/9.1.0/lib64:$LD_LIBRARY_PATH
alias g17="/usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 o ws"
alias g11="g++ -g -Wall -std=c++11 -o ws"

alias fsub="~fardad.soleimanloo/submit"
alias val="valgrind -v --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes"
