# RBF核函数
def rbf_kernel(X1, X2, gamma):
    X1_sq = tf.reduce_sum(tf.square(X1), 1, keepdims=True)
    X2_sq = tf.reduce_sum(tf.square(X2), 1, keepdims=True)
    sq_dists = X1_sq - 2 * tf.matmul(X1, tf.transpose(X2)) + tf.transpose(X2_sq)
    return tf.exp(-gamma * sq_dists)
# 定义线性核函数
def linear_kernel(x1, x2):
    return tf.tensordot(x1, x2, axes=1)

# SVM模型
class SVM(tf.Module):
    def __init__(self):
        self.alpha = tf.Variable(tf.zeros([X_train.shape[0], 1]), dtype=tf.float32)
        self.b = tf.Variable(0.0, dtype=tf.float32)

    def predict(self, X):
        K = rbf_kernel(X, X_train, gamma)
        return tf.sign(tf.matmul(K, self.alpha * y_train[:, None]) + self.b)

# 损失函数
def compute_loss(model, X, y):
    K = rbf_kernel(X, X_train, gamma)
    decision = tf.matmul(K, model.alpha * y_train[:, None]) + model.b
    hinge_loss = tf.reduce_mean(tf.maximum(0.0, 1 - y[:, None] * decision))
    regularization = 0.5 * tf.reduce_sum(model.alpha * y_train[:, None] * tf.matmul(K, model.alpha * y_train[:, None]))
    return C * hinge_loss + regularization

# 创建模型
svm = SVM()

# 优化器
optimizer = tf.optimizers.Adam(learning_rate=0.01)