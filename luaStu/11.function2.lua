-- function 进阶 常见的表现形式
function show(a,b)
    print(a,b);
end

--直接调用
show("abc",123);

--function 当右值赋值给变量
func1 = show;
func1("ade",234); --ade 234

--匿名函数当右值
func2 = function (a,b)
    print(a,b);
end
func2("aasd",123); --aasd 123

--当参数 
function func3(func,a,b)
    func(a,b);
end

func3(show,"abc",123); --abc 123
func3(function (a,b) print(a,b) end, "qwe",123); --匿名临时对象当参数    qwe 123


print("");
--当返回值
function func4()
    return func1;    
end

temp = func4();
temp("abc", 468); -- abc 468
func4()("abcd",123); --相当于直接func1("abcd",123)

--匿名函数当返回值
function func5()
    return function (a,b) print(a..b); end
end

temp2 = func5();
temp2("hello",123);--hello123
func5()("world",456); --world456

--多返回值

function func6()
    function func6_son1(a,b)
        print("son1",a,b);
    end
    
    function func6_son2(a,b)
        print("son2",a,b);
    end
    return func6_son1,
           func6_son2,
           func1,
           function (a,b) print("last",a,b); end
end

temp3,temp4,temp5,temp6 = func6();
temp3("abc",123);
temp4("abc",123);
temp5("abc",123);
temp6("abc",123);


