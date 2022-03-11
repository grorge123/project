contractAddress = "0x4CeF8fA0C1896dF8c3507e0128dF45e29bD35d6C";
contractABI = "./abi.json";

// Pop alert until the network ID is correct
async function checkNetwork() {
    if (window.ethereum.chainId != 4) {
		console.log("Please connect to the Rinkeby Testnet!");
		return false;
	}
	return true;
}


// Check if MetaMask is connected
// Returns bool: Connected to MetaMask or not
// If connected, acc will be set to the default account
async function getAccount() {
    if (!window.ethereum) {
        console.log("MetaMask not installed")
        return false;
    }

    let status = false;
    await window.ethereum.request({ method: 'eth_requestAccounts' })
    .then((accounts) => {
        if (accounts.length) {
            acc = accounts[0];
            status = true;
        }
    })
    .catch((err) => {
        // Some unexpected error.
        // For backwards compatibility reasons, if no accounts are available,
        // eth_accounts will return an empty array.
        console.error(err);
    });
    return status;
}
wallet = 0;
function get_info() {
	contract.methods.result().call().then((re) => {
		$("#addr").text(`${re[0]}`);
		$("#money").text(`${re[1]}`);
		$("#lucky").text(`${re[2]}`);
	}).catch(err => {
		console.error(err);
	})
	contract.methods.get_money().call().then((re) => {
		$("#ym").text(`${re}`);
		wallet = re;
		if (re != 0) {
			$("#reg").css('visibility', 'hidden');
		}
	}).catch(err => {
		console.error(err);
	})
	contract.methods.num().call().then((re) => {
		contract.methods.all().call().then((re2) => {
			$("#less").text(`目前還缺：${10 - re}人 累計獎金：${re2}元`);
		}).catch(err => {
			console.error(err);
		})
	}).catch(err => {
		console.error(err);
	})
	
}

$(document).ready(async function () {
	let init = true;
	
	if (!window.ethereum) {
		console.log("You are not install Metamask");
	}
	
	w3 = new Web3(window.ethereum);

    if (!await getAccount()) init = false;
        // MetaMask is connected
	if (!await checkNetwork()) init = false;
	if (init) {
		w3 = new Web3(window.ethereum);
		w3.eth.defaultAccount = acc;
	
		w3.eth.getBalance(acc, w3.eth.defaultBlock, (e, bal) => {
			$("#acc").text(`${w3.utils.toChecksumAddress(acc)}`);
			address =  w3.utils.toChecksumAddress(acc) ;
		})
		contract = new w3.eth.Contract(await $.get(contractABI), contractAddress);
		get_info();
		var intervalID = setInterval(get_info, 1000);
	}
})

$("#reg").on("click", async function () {
	contract.methods.register().send({from:address}).then((re) => {
		Swal.fire({
			icon: 'success',
			title: 'success',
		})
	}).catch(err => {
		console.error(err);
	})
})

$("#sub").on("click", async function () {
	let money = $("#inp").val();
	money = parseInt(money);
	if (isNaN(money)) {
		Swal.fire({
			icon: 'error',
			title: 'Oops...',
			text: 'money must be integer',
		})
		return;
	}
	if (money > wallet) {
		Swal.fire({
			icon: 'error',
			title: 'Oops...',
			text: 'you do not have enough money',
		})
		return;
	}
	contract.methods.guess(money).send({from:address}).then((re) => {
		Swal.fire({
			icon: 'success',
			title: 'success',
		})
	}).catch(err => {
		console.error(err);
	})
})
