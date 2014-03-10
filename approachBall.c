when navigate returns a 1 and destination=0,1 or 2
open gripper
raise gripper
line follow until BOTH BUMPERS are hit (range finder to control speed?)
lower gripper to correct height
close gripper
call force sensing error checking 
if error function returns 1(no error)
set destination=3
backup (small amount to allow turning)

if error function returns 0 (not gripping ball)
pause and enter shuffle functions by bluetooth
