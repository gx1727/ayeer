var main = require('./controller');

/**
 * 判断参数个数
 * 没有参数时，不操作
 */
if (process.argv.length < 2) {
    console.log("ayeer!!!   ");
    return;
}

/** 获取CMD */
var cmd = process.argv[2];

/** 获取PARAM */
var param = new Array();
var param_index = 3;
while (process.argv[param_index]) {
    param.push(process.argv[param_index]);
    param_index++;
}
main.run(cmd, JSON.stringify(param));