using Printf
@show VERSION

function calc_julia()
    tmp = 0
    total = 0
    for i in 1:10^5
        for j in 1:10^4
            if j % 4 == 0
                tmp = i + j
            elseif j % 4 == 1
                tmp = i - j
            elseif j % 4 == 2
                tmp = i * j
            else
                tmp = i ÷ j
            end
            total += tmp
        end
    end
    total
end

println()
@time total = calc_julia()
@time total = calc_julia()
@time total = calc_julia()

@printf("total = %d\n", total)