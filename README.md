# minmaxbench
Benchmark of singular min max and iterator versions

VC++ update 16.4, /Ox
```
         manual min:  571ms, result:1
            std min:  557ms, result:1
    std min_element: 1856ms, result:1

         manual max:  810ms, result:1000000
            std max:  559ms, result:1000000
    std max_element: 1832ms, result:1000000

     manual min max:  808ms, result:1,1000000
      std min & max:  740ms, result:1,1000000
 std minmax_element: 2149ms, result:1,1000000
```

Clang++ 6.0.0, -O3
```
         manual min:  521ms, result:1
            std min:  419ms, result:1
    std min_element:  386ms, result:1

         manual max:  416ms, result:1000000
            std max:  445ms, result:1000000
    std max_element:  428ms, result:1000000

     manual min max:  701ms, result:1,1000000
      std min & max:  969ms, result:1,1000000
 std minmax_element:  514ms, result:1,1000000
```

G++ 6.0.0, -O3
```
         manual min:  801ms, result:1
            std min:  810ms, result:1
    std min_element:  808ms, result:1

         manual max:  566ms, result:1000000
            std max:  552ms, result:1000000
    std max_element:  555ms, result:1000000

     manual min max:  799ms, result:1,1000000
      std min & max:  796ms, result:1,1000000
 std minmax_element: 2052ms, result:1,1000000
```

