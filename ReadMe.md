libstream
===============


Streamful function for C++

## What a stream

We used the `>>` stream opeator for some continuous function call. It will reduce the callback function used.

eg. When we do some work one by one, and the next function's input will be the last function's return.

```
    auto ret = some.func(args);
    auto ret2 = some.func2(ret);
    auto ret3 = some.func3(ret2);
    ...
```

Sometimes, it will be this:
```
    auto ret = some.func3(some.func2(some.func(args)));
```

We want to change it to this:
```
    func(args) >> some.func >> some.func2 >> some.func3;
    func.call();
    or
    func.callsync();
```
