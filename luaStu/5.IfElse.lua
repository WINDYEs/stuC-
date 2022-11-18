--[[

流程控制语句

if 条件 then
    ...
end
]]--


-- local a,b = 1,2;

-- if a == 1 then
--     print("=1");
-- end

-- if a > 1 then
--     print(">1");
-- else
--     print("<=1");
-- end
-- if a > 1 then
--     print(">1");
-- elseif a==1 then
--     print("=1");
-- else
--     print("<=1");
-- end



local c,d = -123,101;
if c > 100 then
    print("SGod");
elseif c >=90 and c <= 100 then
    print("SKing");
elseif c >=80 and c < 100 then
    print("SLord");
elseif c >=60 and c < 80 then
    print("SMan");
elseif c >= 0 and c < 60 then
    print("Slave");
else
    print("are you serious???");
end