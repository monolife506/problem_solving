v_kappa, j_kappa = map(int, input().split())
v_lambda, j_lambda = map(int, input().split())
vh, dh, jh = map(int, input().split())
print(vh * dh * jh * v_lambda * j_lambda + vh * dh * jh * v_kappa * j_kappa)
