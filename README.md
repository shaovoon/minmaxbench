# minmaxbench
Benchmark of singular min max and iterator versions

VC++ update 16.4, /Ox
```
            manual min:  592ms, result:1
               std min:  630ms, result:1
       std min_element: 1889ms, result:1
   std par min_element: 1901ms, result:1

            manual max:  832ms, result:1000000
               std max:  585ms, result:1000000
       std max_element: 1891ms, result:1000000
   std par max_element: 1883ms, result:1000000

        manual min max:  816ms, result:1,1000000
         std min & max:  762ms, result:1,1000000
    std minmax_element: 2143ms, result:1,1000000
std par minmax_element: 2034ms, result:1,1000000
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

G++ 7.4.0, -O3
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

