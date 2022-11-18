--[[

    赋值=
    lua中变量是弱类型 不用添加类型名 种类按照赋值的种类
    a = 1 number
    b = false boolean 
    a = "123" 同一个变量可以随时切换不同的数据类型 但是会覆盖原来的类型 


    算术运算符
    + - * / % ^

    关系运算符
    等于== 不等于~= 其他都一样
    关系运算符结果只有true false


    逻辑运算符
    & | ！与或非 and or not
    在lua中 只有nil null NULL和false为假 其他都为真(包括0值和空串)
]]--

local a,b,c,d= 1,"abc",true,{123,23};
print(a,b,c,d[2]) --表不加下标会输出该表的地址
--1 abc true 23

-- a,b =2,3;
-- a,b = b,a;
-- print(a,b); --类似swap交换 

--print(1 == '1');

print(1+'23'); --隐式类型转换 24
--print(1+'a'); --隐式类型转换失败




--[[
local info1 = {a = 'a', b = 'b'}; 
local info2 = {a = 'a', b = 'b'}; 
local info3 = info1;
print(info1 == info2); --比较的是地址引用 nil
print(info1 == info3); --指向同1引用   true

print(info1.a == info2.a); --比较的是值

a, b = 1, 2;
print(a and b); -- a为真 返回b
a = false;
print(a and b); -- a为假 返回a

c, d = 1, 2;
print(c or d); --如果c为真 则返回c 不往后运算

c = nil;
print(c or d); --如果c为假 则返回d 


e,f = 1,2;
print(not e); --如果e为真返回假

f = nil;     
print(not f);
]]--

-- 用or 设置默认值
function func1(a,b)
    a = a or 10; -- a = 10
    b = b or 12; -- b = 12
    print(a,b); -- 10 12
end

func1();
func1(23,32); --23 32

--实现三目运算 d = a?b:c  如果a为真则取b否则取c

-- a,b,c = 1,2,3;
-- d=(a and b) or c;
-- print(d);
-- a = false;
-- d=(a and b) or c;
-- print(d);

A,B,C = 1,2,3;
B = false;
D=(A and B) or C;
print(D); --3

E=((A and {B}) or {C})[1]; --正确格式 B和C两个表的第一个元素判断    
print(E);
