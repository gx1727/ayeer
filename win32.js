/**
 * Created by gx1727 on 2016/10/12 0012.
 */
const ayeer_api = require('./addon/ayeer_api/build/Release/ayeer_api');

//移动鼠标
function mouse_move(x, y) {
    var pos = {x: Number(x), y: Number(y)};
    var param = JSON.stringify(pos);

    var win_ret = ayeer_api.do('mouse_move', param);
    return win_ret;
}
exports.mouse_move = mouse_move;


function shell_execute(cmd) {
    var win_ret = ayeer_api.do('shell_execute', cmd);
    return win_ret;
}
exports.shell_execute = shell_execute;


/**
 * 调用系统的MessageBox，提示信息
 * @param msg
 * @returns {*}
 */
function alert(msg) {
    var win_ret = ayeer_api.do('message_box', msg);
    return win_ret;
}
exports.alert = alert;

function sleep(second) {
    var win_ret = ayeer_api.do('sleep', second * 1000);
    return win_ret;
}
function msleep(second) {
    var win_ret = ayeer_api.do('sleep', second);
    return win_ret;
}
exports.sleep = sleep;
exports.msleep = msleep;

function find_window(name, mode) {
    var param = {name: name, mode: mode};
    param = JSON.stringify(param);

    var win_ret = ayeer_api.do('find_window', param);
    return win_ret;
}
exports.find_window = find_window;

function select_window(hwnd) {
    var win_ret = ayeer_api.do('select_window', hwnd);
    return win_ret;
}
exports.select_window = select_window;

/*************************************************************************/
//自动
function run(cmd, param) {
    var win_ret = ayeer_api.do(cmd, param);
    return win_ret;
}
exports.run = run;