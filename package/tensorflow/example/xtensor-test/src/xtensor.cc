/* Copyright 2019 Exein. All Rights Reserved.

Licensed under the GNU General Public License, Version 3.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://www.gnu.org/licenses/gpl-3.0.html

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <iostream>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xadapt.hpp>


int main(int argc, char* argv[])
{
  xt::xarray<int> arr {2, 6, 7, 4, 13};
  std::cout << "input1 " << arr << std::endl;

  //np.roll(arr, -1, axis=0)
  auto res_roll = xt::roll(arr, -1, /*axis*/0);
  std::cout << "roll " << res_roll << std::endl;

  //np.zeros(5)
  auto res_zeros = xt::zeros<double>({5});
  std::cout << "zeros " << res_zeros << std::endl;

  //np.clip(arr, min, max)
  auto res_clip = xt::clip(arr, 3, 11);
  std::cout << "clip " << res_clip << std::endl;

  xt::xarray<int> arr2 {{1, 2, 3}, {4, 5, 6}};
  std::cout << "input2 " << arr2 << std::endl;

  //np.sum(arr, axis=1)
  auto res_sum = xt::sum(arr2, /*axis*/1);
  std::cout << "sum " << res_sum << std::endl;

  //np.expand_dims(a, 0)
  auto res_exd = xt::expand_dims(arr2 ,0).shape();
  std::cout << "expand_dims/reshape " << xt::adapt(res_exd) << std::endl;

  //arr.astype(np.float32)
  auto res_astype = xt::cast<float>(arr);
  std::cout << "astype " << res_astype << std::endl;

  //np.stack([...], axis=1)
  auto res_stack = xt::stack(xt::xtuple(arr, arr), /*axis*/1).shape();
  std::cout << "stack " << xt::adapt(res_stack) << std::endl;

  //np.mean(arr)
  auto res_mean = xt::mean(arr);
  std::cout << "mean " << res_mean << std::endl;

  //np.isin(arr, values)
  std::vector<int> item {2, 13, 5};

  xt::xarray<int>::shape_type sh0 = arr2.shape();
  auto res_isin = xt::empty<int>(sh0);
  res_isin.fill(0);
  for (size_t a = 0; a < arr2.size(); a++) {
    for (auto const& i: item){
      if (arr2[a] == i) {
        res_isin(a) = 1;
        break;
      }
    }
  }
  std::cout << "isin " << res_isin << std::endl;


  return 0;
}
