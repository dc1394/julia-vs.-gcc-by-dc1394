using Distributed
using Printf

@show procs()
@show rmprocs(procs()[2:end])
@show addprocs()
@show procs()
println()

function calc_julia_distributed()
    total = @distributed (+) for i in 1:10^5
        tmp2 = 0

        for j in 1:10^4
            tmp = if j % 4 == 0
                     i + j
                  elseif j % 4 == 1
                     i - j
                  elseif j % 4 == 2
                     i * j
                  else
                     i ÷ j
                  end
            tmp2 += tmp
        end
        tmp2
    end

    return total
end

@time total = calc_julia_distributed()
@time total = calc_julia_distributed()
@time total = calc_julia_distributed()

@printf("total = %d\n", total)