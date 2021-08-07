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

type 
    Action* = ref object of RootObj

    EscapeAction* = ref object of Action

    MovementAction* = ref object of Action 
        dx, dy: int32

proc evalMoveAction*(e: MovementAction): auto = (e.dx, e.dy)

proc newMovementAction*(x, y: int32): Action = MovementAction(dx: x, dy: y)
proc newEscapeAction*(): Action = EscapeAction()