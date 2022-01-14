#!/usr/bin/env bash

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

source "${SCRIPTPATH}/lib/_st_log.sh"

for i_file in "st-urlhandler"
do
  st_log "INFO" "Get latest **${i_file}** from __https://github.com/LukeSmithxyz/st__."
  wget -q "https://raw.githubusercontent.com/LukeSmithxyz/st/master/${i_file}" &> /dev/null
  st_log "INFO" "Check diff between last and new verion. Press **Enter** to continue"
  read
  vimdiff "${SCRIPTPATH}/${i_file}" "${SCRIPTPATH}/src/${i_file}"
  st_log "INFO" "Move it to **src/**."
  mv "${SCRIPTPATH}/${i_file}" "${SCRIPTPATH}/src/${i_file}"
  st_log "INFO" "Make it executable."
  chmod +x "${SCRIPTPATH}/src/${i_file}"
  st_log "INFO" "Copying it to **'~/.local/bin'**."
  cp "${SCRIPTPATH}/src/${i_file}" "${HOME}/.local/bin/${i_file}"
done