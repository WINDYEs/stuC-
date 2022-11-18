--[[
    table
        array
        hash



]]--

--自定义下标
--[[ t1 = {11,22,33};
t1["abcd"] = 555; 
for k,v in ipairs(t1) do --跳过k-v
    print(k,v);
end
print("\n");
for k,v in pairs(t1) do --不跳过k-v
    print(k,v);
end ]]

--二维数组
--[[ t1 = {
    {11,22,33},
    {44,55,66}
};

for i = 1, 2 do
    for j = 1, 3 do
        print(i,j,t1[i][j]);
    end
    print("")
end 

print("");

for k,v in ipairs(t1) do
    for k2,v2 in ipairs(v) do
        print(k,k2,v2); --v2 是 v的值
    end
    print("");
end
]]



--[[ t1 = {};
--循环创建二维表
for i = 1, 3 do
    t1[i] = {}; --初始化表
    for j = 1, 2 do
        t1[i][j] = i * j * 11; --往空表中添加元素
    end
end

for k,v in ipairs(t1) do
    for k2,v2 in ipairs(v) do
        print(k,k2,v2);
    end
    print("")
end ]]
            --sep连接符 i,j开始位置和结束位置
--table.concat(list, sep, i, j)将数组元素拼接成字符串 注意只拼接的字符串元素 和数值 其他元素不拼接
t1 = {"abc","def","hello","123","789","world"};
print(table.concat(t1, "++")); --返回一个由++拼接的所有表中元素连接成的字符串 abc++def++hello++123++789++world

table.remove(t1); --默认移除最后一个元素 (t1,2)移除下标为2的元素 
print(table.concat(t1, "++")); --abc++def++hello++123++789

table.insert(t1,"???"); --元素默认添加到最末尾 (t1,2,"??？")把元素添加到下标2的位置
print(table.concat(t1, "++")); --abc++def++hello++123++789+???

function func1(a,b)
    return a > b;
end
table.sort(t1,func1);--默认把元素从小到大排序 定义方法改为降序
print(table.concat(t1, "++")); --hello++def++abc++???++789++123
t2 ={"aaa","bbb"};
table.move(t1,2,3,3,t2); --拷贝t1中下标2到3的元素放到 t2表中下标3位置
print(table.concat(t2, "--")); -- aaa--bbb--def--abc

