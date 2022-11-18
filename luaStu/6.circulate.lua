--[[
循环
while 条件 do
    ...
end
没有comtinue
goto FLAG 语句 跳转到指定标记处 也可以用于跳出循环  FLAG之前的一些代码可以被忽略掉
a=b=1 写法错误

repeat
    表达式
until 条件

while 和 repeat的区别
    while循环是条件不成立 结束循环  repeat 条件成立 才结束循环


]]--


-- local i,sum =0,0;

-- while i < 100 do
--     --i++ 不行 lua没有
--     if i > 49 then
--         goto FLAG;
--         --break;
--     end


--     i=i+1;
--     sum=sum + i;
-- end

-- print(222)

-- ::FLAG::
-- print(i, sum);


local i,sum =0,0;
repeat
    i = i + 1;
    sum = sum + i;    
until i >=100; --直到i>=100 条件才结束

print(i,sum)

