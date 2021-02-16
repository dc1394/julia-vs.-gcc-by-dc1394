using Printf
@show VERSION

function calc_julia()
    total = 0

    for i in 1:10^5
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
            total += tmp
        end
    end
    
    return total
end

println()
@time total = calc_julia()
@time total = calc_julia()
@time total = calc_julia()

@printf("total = %d\n", total)
