using Distributed
using Printf
@show VERSION
addprocs()

function calc_julia_distributed()
    total = @distributed (+) for i in 1:10^5
        tmp = Vector{Int64}(undef, 10^4)
        for j in 1:10^4
            tmp[j] = if j % 4 == 0
                        i + j
                     elseif j % 4 == 1
                        i - j
                     elseif j % 4 == 2
                        i * j
                     else
                        i ÷ j
                     end
        end
        sum(tmp)
    end

    return total
end

@time total = calc_julia_distributed()
@time total2 = calc_julia_distributed()
@time total3 = calc_julia_distributed()

@printf("total = %d\n", total)
@printf("total = %d\n", total)
@printf("total = %d\n", total)