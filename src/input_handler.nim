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

import options
import actions
import libtcod

proc ev_keydown*(key: Key): Option[Action] =
    case key.vk:
        of K_UP:
            return some(newMovementAction(0, -1))
        of K_DOWN:
            return some(newMovementAction(0, 1))
        of K_LEFT:
            return some(newMovementAction(-1, 0))
        of K_RIGHT:
            return some(newMovementAction(1, 0))
        of K_ESCAPE:
            return some(newEscapeAction())
        else:
            return none(Action)