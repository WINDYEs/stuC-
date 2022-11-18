-- function 进阶 table 中的function
function show(a,b)
    print(a,b);
end

t1 = {
    t1_show = function (a) print(a); end,
    t1_add = function (a,b)
        return a+b;
    end,

    t1_sub = function (a,b)
        return a-b;
    end,

    t1_mul = function (a,b)
        return a*b;
    end
};
t1.t1_show(123);
t1["t1_show"](423);
t1.t1_show(t1.t1_add(11,22)); --33
t1.t1_show(t1.t1_sub(23,12)); -- 11
t1.t1_show(t1.t1_mul(10,12)); --120



t2 = {
    a = 0,
    b = 0,
    result = 0,
    t2_show = function () print(t2.result); end,
    t2_add = function ()
        t2.result = t2.a + t2.b; --类似this
    end,

    t2_sub = function ()
        t2.result = t2.a - t2.b; --类似this
    end,

    t2_mul = function ()
        t2.result = t2.a * t2.b; --类似this
    end
};
t2.a = 12;
t2.b = 11;
t2.t2_add(); -- 12 + 11
t2.t2_show();  --result = 23


--注意这里是引用 假如t2赋值nil 下面将失去本来要引用的空间
temp = t2;
temp.t2_mul();  --12 * 11 132
temp.t2_show(); --132