local robot = require ("robot")

local tArgs = { ... }
if #tArgs ~= 2 then
    print("Usage:miner <length> <Minerals-number>")
    return
end

local length = tArgs[1]
local comparenum_start = 16 - tArgs[2] + 1
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
function compare ()
    if robot.detect() then
        return true
    end
    for i = comparenum_start, 16 do
        robot.select(i)
        if robot.compare() then
            return true
        end
    end
    return false
end
function compareUp ()
    if robot.detect() then
        return true
    end
    for i=comparenum_start,16 do
        robot.select(i)
        if robot.compareUp() then
            return true
        end
    end
    return false
end
function compareDown ()
    if robot.detect() then
        return true
    end
    for i=comparenum_start,16 do
        robot.select(i)
        if robot.compareDown() then
            return true
        end
    end
    return false
end
function dfsforward ()
    robot.turnLeft()
    if(compare()) then
        robot.swing()
        forward()
        dfsForward()
        back()
    end
    for i = 1, 2 do
        robot.turnRight()
        if(compare()) then
            robot.swing()
            forward()
            dfsForward()
            back()
        end
    end
    robot.turnLeft()
    if(compareUp()) then
        robot.swingUp()
        up()
        dfsUp()
        down()
    end
    if(compareDown()) then
        robot.swingDown()
        down()
        dfsDown()
        up()
    end
end
function dfsUp ()
    for i=1,4 do
        if (compare()) then
            robot.swing()
            forward()
            dfsforward()
            back()
        end
        robot.turnRight()
    end
    if(compareUp()) then
        robot.swingUp()
        up()
        dfsUp()
        down()
    end
end
function dfsDown ()
    for i=1,4 do
        if(compare()) then
            robot.swing()
            forward()
            dfsForward()
            back()
        end
        robot.turnRight()
    end
    if(compareDown())then
        robot.swingDown()
        down()
        dfsDown()
        up()
    end
end
print("Program start...")
for i=1,length do
    robot.swing()
    forward()
    robot.turnLeft()
    if compare() then
        robot.swing()
        forward()
        dfsforward()
        back()
    end
    robot.turnAround()
    if compare() then
        robot.swing()
        forward()
        dfsForward()
        back()
    end
    robot.turnLeft()
    if compareUp() then
        robot.swingUp()
        up()
        dfsUp()
        down()
    end
    if compareDown() then
        robot.swingDown()
        down()
        dfsDown()
        up()
    end
end
robot.turnAround()
for i=1,length do
    forward()
end
