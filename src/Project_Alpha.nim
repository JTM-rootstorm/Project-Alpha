#[
     Copyright 2021 mike j

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
]#

import libtcod
include input_handler

const screen_width : int32 = 80
const screen_height : int32 = 50

var player_x = cint(screen_width / 2)
var player_y = cint(screen_height / 2)

var key : Key
var mouse : Mouse

let font : cstring = "/data/fonts/dejavu10x10_gs_tc.png"
let fontFlags : cint = FONT_TYPE_GREYSCALE or FONT_LAYOUT_TCOD
let renderer : Renderer = RENDERER_OPENGL2

consoleSetCustomFont(font, fontFlags, 0, 0)
consoleInitRoot(screen_width, screen_height, "libtcod test", false, renderer)

while true:
  consolePutChar(nil, player_x, player_y, '@')
  consoleFlush()
  consoleClear(nil)

  discard sysCheckForEvent((EVENT_KEY_PRESS.ord), addr(key), addr(mouse))
  var action: Option[Action] = ev_keydown(key)

  if action.isNone():
    continue
  elif action.isSome():
    var subAction = action.get

    if subAction of MovementAction:
      var (tx, ty) = evalMoveAction(MovementAction(subAction))
      player_x += tx
      player_y += ty
    elif subAction of EscapeAction:
      libtcod.quit()
      quit(0)
