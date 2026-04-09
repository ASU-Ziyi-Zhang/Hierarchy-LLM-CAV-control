#!/bin/sh

# ------------------
## ANSI ESCAPE CODES
# ------------------
NOCOLOR='\033[m'
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'

info() {
    echo -e "${BLUE}[INFO] $1${NOCOLOR}"
}

success() {
    echo -e "${GREEN}[OK] $1${NOCOLOR}"
}

warn() {
    echo -e "${YELLOW}[WARN] $1${NOCOLOR}"
}

error() {
    echo -e "${RED}[ERROR] $1${NOCOLOR}"
}

# ------------------
## Check for cmake install
# ------------------
if ! command -v cmake 2>&1 >/dev/null
then
    error "cmake could not be found! Exiting controller installation. Please install/fix cmake and then try again."
    
    return 1 || exit 1
    
fi

# ------------------
## PCC
# ------------------
cd pcc_codegen

# Install PCC
. install.sh

if [ $? != 0 ]; then # last command # Check if it was successful
    error "Installing PCC failed."
    return 1 || exit 1
fi

# Copy PCC
. copy.sh

if [ $? != 0 ]; then # last command # Check if it was successful
    error "Copying PCC failed."
    return 1 || exit 1
fi

cp _cppwrapper.py ../../src/pcc_cppwrapper.py

if [ $? != 0 ]; then # last command # Check if it was successful
    error "Copying wrapper for PCC failed."
    return 1 || exit 1
fi

success "PCC installed and copied successfully."

cd ..

# ------------------
## CAV Eco-approach
# ------------------
cd cavctrl_codegen


. install.sh
. copy.sh

cp _cwrapper.py ../../src/cav_cwrapper.py

success "CAV Eco-approach installed and copied successfully."

cd ..
