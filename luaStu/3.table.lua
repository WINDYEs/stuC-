--[[
    格式 类似hash
    tableName = {
        k = v,
        k1 = v1
    }

    类似于数组 下标从1开始
    tableName = {"abc",132,true};


]]--


--table 是一种数据类型 类似与map 用k-v实现 除了nil都可以作为key值
local info = {
    id = 23,
    name = "jack",
    isMale = true
};
--for循环遍历 for k,v in pairs(tableName) do
    --          print(key,value);       
    --        end
-- for k,v in pairs(info) do
--     print( k, " = ", v);
-- end
--print("\n");

--增加字段
--info.age = 123;
--info["coutry"] = "china";

--删除字段
--info.isMale = nil;
info["isMale"] = nil;

--修改字段
--info.name = "rose";
--info.isMale = "false";


-- for k,v in pairs(info) do
--     print( k, " = ", v);
-- end

--print("\n");

local info2 = {23,"abc",true};

-- for k,v in pairs(info2) do
--     print(k, " = ", v);
-- end
print("\n");
--增加
info2[4] = 23;

--修改
info2[2] = "jack";


--删除
info2[1] = nil;

-- for k,v in pairs(info2) do
--     print(k, " = ", v);
-- end

local info3 = { --没自定义key的默认为数字下标 遍历优先默认输出数字下标元素开始 ，然后再到键值对 
        name = "tome",
        age = 132,
        isMale = false,
        111,
        "222",
        {"bcd","ecf",781,son_k_1 = "son-key-1"},
        son2 = {son2_k_1 = "son2_key_1", name = "son2", false, "abc-son2", 123456},
        lang = "chinese",
        333
}

for k,v in pairs(info3) do
    print(k, " = " ,v);
    if type(v) == "table" then --如果table中有value值是table 就把它的元素遍历出来
        for k2, v2 in pairs(v) do
            print("\t", k2, " = ", v2); --缩进一个制表符 输出
        end
    end
end


--删除字段
info3.isMale = nil;
info3[1] = nil;

--修改字段
info3[3][1] = "abc";
info3["son2"][1] = true;
--增加字段
info3.work = "student";
info3[3][4] = 444;

print("\n");

for k,v in pairs(info3) do
    print(k, " = " ,v);
    if type(v) == "table" then --如果table中有v的值是table 就把它的元素遍历出来
        for k2, v2 in pairs(v) do
            print("\t", k2, " = ", v2); --缩进一个制表符 输出
        end
    end
end