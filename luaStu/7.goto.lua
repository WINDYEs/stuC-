--[[


    do
        --类似c++代码块
    end
    1.flag不可见原则不能goto到代码块里的FLAG
    2.不能跳出一个函数或者跳入一个函数 ，因为函数也是一个代码块
    3.不能跳入本地变量作用域
]]--

do
    local a = 123;
    print(a);
end
goto FLAG2;
--[[

print(a);
死循环
i = 0;
::FLAG1::
    print(i);
    i = i + 1;
goto FLAG1;


]]--
do
    print("a");
    print("B");
    ::FLAG3::
    print("inside");
end

::FLAG2::
print("public");

function func()
    ::FLAG4::;
    print("func1-11");
    print("func2-22");
    print("func3-33");
    goto FLAG4;
end 
func();
print("aaa");
print("bbb");



