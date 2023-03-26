import Control.Parallel.Strategies (parMap, rdeepseq)
import Data.List (foldl')

gcd' :: Int -> Int -> Int
gcd' a b
  | b == 0 = a
  | otherwise = gcd' b (a `mod` b)

phi :: Int -> Int
phi n = length $ filter (\i -> gcd' i n == 1) [1..n-1]

sumPhi :: Int -> Int
sumPhi n = foldl' (+) 0 $ parMap rdeepseq phi [2..n]

main :: IO ()
main = do
  let n = 1000
  let result = sumPhi n
  putStrLn $ "Sum of Euler totient values from 2 to " ++ show n ++ ": " ++ show result