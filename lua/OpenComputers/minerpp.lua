local robot = require ("robot")

local tArgs = { ... }
if #tArgs ~= 1 then
    print("Usage:minerpp <length>")
    return
end

local length = tArgs[1]
local start = 16 - 6 + 1

--Move
function forward ()
    while not robot.forward() do
        robot.swing()
    end
end
function up ()
    while not robot.up() do
        robot.swingUp()
    end
end
function down ()
    while not robot.down() do
        robot.swingDown()
    end
end
function back ()
    if not robot.back() then
        robot.turnAround()
        forward()
        robot.turnAround()
    end
end

--Compare
function compare ()
    if not robot.detect() then
        return false
    end
    for i=start,16 do
        robot.select(i)
        if robot.compare() then
            return true
        end
    end
    return false
end
function compareDown ()
    if not robot.detectDown() then
        return false
    end
    for i=start,16 do
        robot.select(i)
        if robot.compareDown() then
            return true
        end
    end
    return false
end
function compareUp ()
    if not robot.detectUp() then
        return false
    end
    for i=start,16 do
        robot.select(i)
        if robot.compareUp() then
            return true
        end
    end
    return false
end


--寻矿
function dForward ()
    robot.turnLeft()
    if compare() then
        robot.swing()
        forward()
        dForward()
        back()
    end

    for i=1,2 do
        robot.turnRight()
        if compare() then
            robot.swing()
            forward()
            dForward()
            back()
        end
    end
    robot.turnLeft()
    if compareUp() then
        robot.swingUp()
        up()
        dUp()
        down()
    end
    if compareDown() then
        robot.swingDown()
        down()
        dDown()
        up()
    end
end

function dUp ()
    for i=1,4 do
        if compare() then
            robot.swing()
            forward()
            dForward()
            back()
        end
        robot.turnRight()
    end

    if compareUp() then
        robot.swingUp()
        up()
        dUp()
        down()
    end
end

function dDown ()
    for i=1,4 do
        if compare() then
            robot.swing()
            forward()
            dForward()
            back()
        end
        robot.turnRight()
    end
    if compareDown() then
        robot.swingDown()
        down()
        dDown()
        up()
    end
end


----main
print("Program Starts...")
for i=1,length do
    forward()
    robot.turnLeft()
    if compare() then
        robot.swing()
        forward()
        dForward()
        back()
    end
    robot.turnAround()
    if compare() then
        robot.swing()
        forward()
        dForward()
        back()
    end
    robot.turnLeft()
    if compareUp() then
        robot.swingUp()
        up()
        dUp()
        down()
    end
    if compareDown() then
        robot.swingDown()
        down()
        dDown()
        up()
    end
end
robot.turnAround()
for i=1,length do
    forward()
end


for i=1,16 do
    robot.select(i)
    robot.drop()
end