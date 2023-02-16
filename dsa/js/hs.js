const array = [1, 5, 4, 33, 86, 56, 45, 34, 2, 8, 6, 7, 14, 12, 40];
console.log(array.length)
function sort(arr, n) {
  for (var i = Math.floor((n /2)); i >= 0; i--) {
    heapify(arr, n, i);
  }

  // swap 1st elem with last elem
  for (var i = n; i > 0; i--) {
    var temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0);
  }
}

function heapify(arr, n, i) {
  var largest = i;
  var left = 2 * i + 1;
  var right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    	  var swap = arr[i];
          arr[i] = arr[largest];
          arr[largest] = swap;

    heapify(arr, n, largest);
  }
}

function prinnt(arr) {
    for (var i = 0; i < arr.length; ++i){
        console.log(arr[i] + "")
    }
}


sort(array, array.length);

prinnt(array)
