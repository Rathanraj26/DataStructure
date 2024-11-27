
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
   
int *nums3;
nums3=(int*)malloc((m+n)*sizeof(int));
int i=0,j=0,k=0;
while(i<m&&j<n){
    if(nums1[i]<nums2[j])
    nums3[k++]=nums1[i++];
    else
    nums3[k++]=nums2[j++];
} 
while(i<m)
nums3[k++]=nums1[i++];
while(j<n)
nums3[k++]=nums2[j++]; 
for(int i=0;i<m+n;i++)
nums1[i]=nums3[i];

free(nums3);
}
