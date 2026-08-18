const flipAndInvertImage = function(A) {
    return A.map(image => image.reverse().map( b => b === 0 ? 1 : 0));
};