require 'benchmark'
require_relative 'sudoku'

include Benchmark

$puzzle = <<-END
1 . . . . . . . .
6 . . . . . . . .
5 . . . . . . . .
4 . . . . . . . .
8 1 2 3 6 7 9 4 5
9 . . . . . . . .
2 . . . . . . . .
3 . . . . . . . .
7 . . . . . . . .
END

def run_benchmark
  n = 10
  bm(12) do |test|  
    test.report("original:") do
      n.times do
        Sudoku.solve(Sudoku::Puzzle.new($puzzle))
      end
    end  
  end
end

run_benchmark
#puts Sudoku.solve(Sudoku::Puzzle.new($puzzle))

