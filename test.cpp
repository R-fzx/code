#include <functional>
#include <random>
#include <vector>
class FeedforwardNeuralNetwork {
 public:
  FeedforwardNeuralNetwork(std::mt19937 *const &randomNumberGeneration, const unsigned &inNum, const std::vector<unsigned> &neuralNum, const std::function<double(const double &)> &activationFunction, const std::function<double(const double &)> &activationFunctionDerivative);
  std::vector<double> calculate(const std::vector<double> &in) const;
  void train(const std::vector<double> &in, const std::vector<double> &desiredOut, const double &learningRate);

 private:
  class NeuralLayer {
   public:
    NeuralLayer(std::mt19937 *const &randomNumberGeneration, const unsigned &neuralNumForLastLayer, const unsigned &neuralNumForThisLayer, const std::function<double(const double &)> &activationFunction, const std::function<double(const double &)> &activationFunctionDerivative);
    std::pair<std::vector<double>, std::vector<double> > forward(const std::vector<double> &outForLastLayer) const;
    std::vector<double> backward(const std::vector<double> &inForThisLayer, const std::vector<double> &outForThisLayer, const std::vector<double> &desiredOut) const;
    std::vector<double> backward(const std::vector<double> &inForThisLayer, const std::vector<std::vector<double> > &weightForNextLayer, const std::vector<double> &gradientForNextLayer) const;
    void adjust(const std::vector<double> &outForLastLayer, const std::vector<double> &gradientForThisLayer, const double &learningRate);
    std::vector<std::vector<double> > weight;
    std::vector<double> bias;
    const std::function<double(const double &)> activationFunction;
    const std::function<double(const double &)> activationFunctionDerivative;
  };
  std::vector<std::pair<std::vector<double>, std::vector<double> > > forward(const std::vector<double> &in) const;
  std::vector<std::vector<double> > backward(const std::vector<std::pair<std::vector<double>, std::vector<double> > > &ans, const std::vector<double> &desiredOut) const;
  void adjust(const std::vector<double> &in, const std::vector<std::vector<double> > &outForEachLayer, const std::vector<std::vector<double> > &gradientForEachLayer, const double &learningRate);

 public:
  std::vector<NeuralLayer> layer;
};
FeedforwardNeuralNetwork::FeedforwardNeuralNetwork(std::mt19937 *const &randomNumberGeneration, const unsigned &inNum, const std::vector<unsigned> &neuralNum, const std::function<double(const double &)> &activationFunction, const std::function<double(const double &)> &activationFunctionDerivative) {
  for (unsigned i = 1; i <= neuralNum.size(); i++)
    layer.push_back(i < 2 ? NeuralLayer(randomNumberGeneration, inNum, neuralNum.at(i - 1), activationFunction, activationFunctionDerivative) : NeuralLayer(randomNumberGeneration, neuralNum.at(i - 2), neuralNum.at(i - 1), activationFunction, activationFunctionDerivative));
}
std::vector<double> FeedforwardNeuralNetwork::calculate(const std::vector<double> &in) const  //输出最终结果
{
  return forward(in).back().second;
}
void FeedforwardNeuralNetwork::train(const std::vector<double> &in, const std::vector<double> &desiredOut, const double &learningRate) {
  std::vector<std::pair<std::vector<double>, std::vector<double> > > ans = forward(in);
  std::vector<std::vector<double> > gradient = backward(ans, desiredOut);
  std::vector<std::vector<double> > outForEachLayer;
  for (unsigned i = 1; i <= layer.size(); i++)
    outForEachLayer.push_back(ans.at(i - 1).second);
  adjust(in, outForEachLayer, gradient, learningRate);
}
FeedforwardNeuralNetwork::NeuralLayer::NeuralLayer(std::mt19937 *const &randomNumberGeneration, const unsigned &neuralNumForLastLayer, const unsigned &neuralNumForThisLayer, const std::function<double(const double &)> &_activationFunction, const std::function<double(const double &)> &_activationFunctionDerivative) : activationFunction(_activationFunction),
                                                                                                                                                                                                                                                                                                                              activationFunctionDerivative(_activationFunctionDerivative) {
  for (unsigned i = 1; i <= neuralNumForThisLayer; i++) {
    weight.push_back(std::vector<double>());
    for (unsigned j = 1; j <= neuralNumForLastLayer; j++)
      weight[i - 1].push_back((*randomNumberGeneration)() / (double)0xffffffff * 2.0 - 1.0);
    bias.push_back((*randomNumberGeneration)() / (double)0xffffffff * 2.0 - 1.0);
  }
}
std::pair<std::vector<double>, std::vector<double> > FeedforwardNeuralNetwork::NeuralLayer::forward(const std::vector<double> &outForLastLayer) const  //前向传播
{
  std::vector<double> in;   //激活前
  std::vector<double> out;  //激活后
  for (unsigned i = 1; i <= weight.size(); i++) {
    in.push_back(0.0);
    for (unsigned j = 1; j <= weight.at(i - 1).size(); j++)
      in[i - 1] += outForLastLayer.at(j - 1) * weight.at(i - 1).at(j - 1);
    in[i - 1] += bias.at(i - 1);
    out.push_back(activationFunction(in[i - 1]));
  }
  return make_pair(in, out);
}
std::vector<double> FeedforwardNeuralNetwork::NeuralLayer::backward(const std::vector<double> &inForThisLayer, const std::vector<double> &outForThisLayer, const std::vector<double> &desiredOut) const  //计算输出层局部微分
{
  std::vector<double> gradient;
  for (unsigned i = 1; i <= weight.size(); i++)
    gradient.push_back(2 * (outForThisLayer.at(i - 1) - desiredOut.at(i - 1)) * activationFunctionDerivative(inForThisLayer.at(i - 1)));
  return gradient;
}
std::vector<double> FeedforwardNeuralNetwork::NeuralLayer::backward(const std::vector<double> &inForThisLayer, const std::vector<std::vector<double> > &weightForNextLayer, const std::vector<double> &gradientForNextLayer) const  //计算隐藏层局部微分
{
  std::vector<double> gradient;
  for (unsigned i = 1; i <= weight.size(); i++)
    gradient.push_back(0.0);
  for (unsigned i = 1; i <= weightForNextLayer.size(); i++)
    for (unsigned j = 1; j <= weightForNextLayer.at(i - 1).size(); j++)
      gradient[j - 1] += weightForNextLayer.at(i - 1).at(j - 1) * gradientForNextLayer.at(i - 1);
  for (unsigned i = 1; i <= gradient.size(); i++)
    gradient[i - 1] *= activationFunctionDerivative(inForThisLayer.at(i - 1));
  return gradient;
}
void FeedforwardNeuralNetwork::NeuralLayer::adjust(const std::vector<double> &outForLastLayer, const std::vector<double> &gradientForThisLayer, const double &learningRate)  //调整参数
{
  for (unsigned i = 1; i <= weight.size(); i++)
    for (unsigned j = 1; j <= weight.at(i - 1).size(); j++)
      weight[i - 1][j - 1] -= learningRate * gradientForThisLayer.at(i - 1) * outForLastLayer.at(j - 1);
  for (unsigned i = 1; i <= bias.size(); i++)
    bias[i - 1] -= learningRate * gradientForThisLayer.at(i - 1);
}
std::vector<std::pair<std::vector<double>, std::vector<double> > > FeedforwardNeuralNetwork::forward(const std::vector<double> &in) const {
  std::vector<std::pair<std::vector<double>, std::vector<double> > > ans;
  for (unsigned i = 1; i <= layer.size(); i++)
    ans.push_back(layer.at(i - 1).forward(i < 2 ? in : ans.at(i - 2).second));
  return ans;
}
std::vector<std::vector<double> > FeedforwardNeuralNetwork::backward(const std::vector<std::pair<std::vector<double>, std::vector<double> > > &ans, const std::vector<double> &desiredOut) const {
  std::vector<std::vector<double> > gradient;
  for (unsigned i = layer.size(); i >= 1; i--)
    if (i == layer.size())
      gradient.push_back(layer.at(i - 1).backward(ans.at(i - 1).first, ans.at(i - 1).second, desiredOut));
    else
      gradient.push_back(layer.at(i - 1).backward(ans.at(i - 1).first, layer.at(i).weight, gradient.at(layer.size() - i - 1)));
  for (unsigned i = 1, j = gradient.size(); i < j; i++, j--)
    swap(gradient[i - 1], gradient[j - 1]);
  return gradient;
}
void FeedforwardNeuralNetwork::adjust(const std::vector<double> &in, const std::vector<std::vector<double> > &outForEachLayer, const std::vector<std::vector<double> > &gradientForEachLayer, const double &learningRate) {
  for (unsigned i = 1; i <= layer.size(); i++)
    layer[i - 1].adjust(i < 2 ? in : outForEachLayer.at(i - 2), gradientForEachLayer.at(i - 1), learningRate);
}
#include <math.h>
#define E 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274
double Sigmoid(const double &a) {
  return 1.0 / (1.0 + pow(E, -a));
}
double SigmoidDerivative(const double &a) {
  return Sigmoid(a) * (1 - Sigmoid(a));
}
#undef E
#include <math.h>
#define E 2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274
double Tanh(const double &a) {
  return (pow(E, a) - pow(E, -a)) / (pow(E, a) + pow(E, -a));
}
double TanhDerivative(const double &a) {
  return (4.0 * pow(E, 2.0 * a)) / ((pow(E, 2.0 * a) + 1.0) * (pow(E, 2.0 * a) + 1.0));
}
#undef E
double ReLU(const double &a) {
  if (a > 0.0)
    return a;
  else
    return 0.0;
}
double ReLUDerivative(const double &a) {
  if (a >= 0.0)
    return 1.0;
  else
    return 0.0;
}
#include <stdio.h>
void printNetwork(const FeedforwardNeuralNetwork &network) {
  for (unsigned i = 1; i <= network.layer.size(); i++) {
    printf("Layer %u:\n", i);
    for (unsigned j = 1; j <= network.layer.at(i - 1).weight.size(); j++) {
      printf("    Node %u:\n", j);
      printf("        Weight:");
      for (unsigned k = 1; k <= network.layer.at(i - 1).weight.at(j - 1).size(); k++)
        printf("%lf ", network.layer.at(i - 1).weight.at(j - 1).at(k - 1));
      printf("\n");
      printf("        Bias:%lf\n", network.layer.at(i - 1).bias.at(j - 1));
    }
  }
  printf("\n");
}
void train(FeedforwardNeuralNetwork *const &network, const std::vector<std::pair<std::vector<double>, std::vector<double> > > &trainSet, const double &learningRate, const unsigned &roundNum, const unsigned &frequency = 1) {
  printf("Start train\n");
  for (unsigned k = 1; k <= roundNum; k++) {
    double loss = 0.0;
    for (unsigned i = 1; i <= trainSet.size(); i++) {
      network->train(trainSet.at(i - 1).first, trainSet.at(i - 1).second, learningRate);
      std::vector<double> out(network->calculate(trainSet.at(i - 1).first));
      for (unsigned j = 1; j <= out.size(); j++)
        loss += (trainSet.at(i - 1).second.at(j - 1) - out.at(j - 1)) * (trainSet.at(i - 1).second.at(j - 1) - out.at(j - 1));
      if (k % frequency == 0) {
        printf("In:[");
        for (unsigned j = 1; j <= trainSet.at(i - 1).first.size(); j++)
          printf("%lf,", trainSet.at(i - 1).first.at(j - 1));
        printf("]\nDesired Out:[");
        for (unsigned j = 1; j <= trainSet.at(i - 1).second.size(); j++)
          printf("%lf,", trainSet.at(i - 1).second.at(j - 1));
        printf("]\nOut:[");
        for (unsigned j = 1; j <= out.size(); j++)
          printf("%lf,", out.at(j - 1));
        printf("]\n\n");
      }
    }
    loss /= trainSet.size();
    if (k % frequency == 0) {
      printf("Loss:%lf\n", loss);
      printNetwork(*network);
    }
  }
  printf("Finished train\n");
}
void test(FeedforwardNeuralNetwork *const &network, const std::vector<std::pair<std::vector<double>, std::vector<double> > > &testSet) {
  printf("Start test\n");
  double loss = 0.0;
  for (unsigned i = 1; i <= testSet.size(); i++) {
    std::vector<double> out(network->calculate(testSet.at(i - 1).first));
    for (unsigned j = 1; j <= out.size(); j++)
      loss += (testSet.at(i - 1).second.at(j - 1) - out.at(j - 1)) * (testSet.at(i - 1).second.at(j - 1) - out.at(j - 1));
    printf("In:[");
    for (unsigned j = 1; j <= testSet.at(i - 1).first.size(); j++)
      printf("%lf,", testSet.at(i - 1).first.at(j - 1));
    printf("]\nDesired Out:[");
    for (unsigned j = 1; j <= testSet.at(i - 1).second.size(); j++)
      printf("%lf,", testSet.at(i - 1).second.at(j - 1));
    printf("]\nOut:[");
    for (unsigned j = 1; j <= out.size(); j++)
      printf("%lf,", out.at(j - 1));
    printf("]\n\n");
  }
  loss /= testSet.size();
  printf("Loss:%lf\n", loss);
  printf("Finished test\n");
}
#include <ctime>
#include <random>
int main() {
  std::mt19937 randomNumberGeneration(time(nullptr));
  unsigned inNum = 2;
  std::vector<unsigned> neuralNum;
  neuralNum.push_back(3);
  neuralNum.push_back(3);
  neuralNum.push_back(1);
  FeedforwardNeuralNetwork network(&randomNumberGeneration, inNum, neuralNum, std::bind(Sigmoid, std::placeholders::_1), std::bind(SigmoidDerivative, std::placeholders::_1));
  std::vector<std::pair<std::vector<double>, std::vector<double> > > trainSet;
  for (int i = 1; i <= 10000; i++) {
    std::vector<double> in;
    in.push_back(randomNumberGeneration() / (double)0xffffffff * 20.0 - 10.0);
    in.push_back(randomNumberGeneration() / (double)0xffffffff * 20.0 - 10.0);
    std::vector<double> out;
    if (in.at(0) > 0.0) {
      if (in.at(1) > 0.0) {
        out.push_back(1.0);
      } else {
        out.push_back(0.0);
      }
    } else {
      if (in.at(1) > 0.0) {
        out.push_back(0.0);
      } else {
        out.push_back(1.0);
      }
    }
    trainSet.push_back(std::make_pair(in, out));
  }
  std::vector<std::pair<std::vector<double>, std::vector<double> > > testSet;
  for (int i = 1; i <= 50; i++) {
    std::vector<double> in;
    in.push_back(randomNumberGeneration() / (double)0xffffffff * 20.0 - 10.0);
    in.push_back(randomNumberGeneration() / (double)0xffffffff * 20.0 - 10.0);
    std::vector<double> out;
    if (in.at(0) > 0.0) {
      if (in.at(1) > 0.0) {
        out.push_back(1.0);
      } else {
        out.push_back(0.0);
      }
    } else {
      if (in.at(1) > 0.0) {
        out.push_back(0.0);
      } else {
        out.push_back(1.0);
      }
    }
    testSet.push_back(std::make_pair(in, out));
  }
  train(&network, trainSet, 0.03, 100, 10);
  test(&network, testSet);
}