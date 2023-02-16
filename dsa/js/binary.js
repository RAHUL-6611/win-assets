function binary(arr,x,l,r){
    if (l<=r){
        let mid = l + Math.floor((r-l)/2);

        if (arr[mid] == x){
            console.log(mid);
            return mid;
        }
        if (x < arr[mid]){
            return binary(arr,x,l,mid-1)
        }
        if (x > arr[mid]) {
            return binary(arr,x,mid+1,r)

        }
    }

    return -1

}

const arr = [1,2,4,6,7,9,13,17,21,22,25,56,67]
console.log(binary(arr,21,0,arr.length))


{/* function binarySearch(arr, l, r, x){
	if (r >= l) {
		let mid = l + Math.floor((r - l) / 2);

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

let arr = [ 2, 3, 4, 10, 40 ];
let x = 10;
let n = arr.length
let result = binarySearch(arr, 0, n - 1, x);
(result == -1) ? document.write( "Element is not present in array")
				: document.write("Element is present at index " +result); */}
