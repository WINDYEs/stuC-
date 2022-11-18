--[[

for循环 数值循环 和泛型循环
for 变量名 = 初始值, 结束值, 步长（默认1，可省）do
    ...
end


泛型循环
for k,v in 迭代函数(table) do 此处v可以神略   
    
end
迭代函数 ipairs pairs
ipairs 顺序遍历下标系统自己提供 遇到k-value值直接跳过数字下标不会变 遇到value值为nil直接终止 适用于数组类型的集合遍历


pairs 遇到nil会跳过 优先输出数字下标，后面再是key value下标
]]--
--99乘法
for i = 1, 9 do --控制被乘数
    for j = 1, i do
        io.write(j,"*",i,"=",i*j); --控制乘数
        io.write("\t");
    end
    io.write("\n"); --该被乘数在九九乘法中的所有乘法
end 

t1 = {11,nil,key = "aaa",22,33,44,55};
for k,v in pairs(t1) do
    print(k,v);
end


--[[
t1 = {11,22,key = "AA",33,nil,44};

for k,v in ipairs(t1) do
    print(k,v); --省略一个参数 默认输出的是键
end

]]--


-- for i = 1, 10, 2 do
--     io.write(i, " ");
-- end
-- io.write("\n");
-- for i = -10, 0, 1 do
--     io.write(i, " ");
-- end

-- io.write("\n");

-- t1 = {"aa","bb","cc","dd"};
-- for i =  1, 4 do
--     --t1[i] = t1[i] * 10
--     io.write(t1[i], " ");
-- end