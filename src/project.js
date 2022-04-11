window.__require=function e(t,o,i){function n(c,a){if(!o[c]){if(!t[c]){var l=c.split("/");if(l=l[l.length-1],!t[l]){var d="function"==typeof __require&&__require;if(!a&&d)return d(l,!0);if(r)return r(l,!0);throw new Error("Cannot find module '"+c+"'")}}var s=o[c]={exports:{}};t[c][0].call(s.exports,function(e){return n(t[c][1][e]||e)},s,s.exports,e,t,o,i)}return o[c].exports}for(var r="function"==typeof __require&&__require,c=0;c<i.length;c++)n(i[c]);return n}({Goomba:[function(e,t,o){"use strict";cc._RF.push(t,"874ecK8IvRFRr8Me1GCVDUg","Goomba"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=e("./Mario"),a=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.player=null,t.isDead=!1,t.moveDirection=!1,t.anim=null,t}return __extends(t,e),t.prototype.onLoad=function(){this.anim=this.getComponent(cc.Animation)},t.prototype.start=function(){this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,0),this.node.scaleX=-1},t.prototype.onBeginContact=function(e,t,o){if(!this.isDead)if("Mario"==o.node.name){if(this.player.isInvincible||this.player.isDead)return void(e.disabled=!0);cc.log(e.getWorldManifold().normal.x,e.getWorldManifold().normal.y,0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y>=.9),0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y>=.9?(cc.log("destory"),this.player.jump(),this.player.score+=100,this.anim.play("Goomba"),this.isDead=!0,this.scheduleOnce(function(){this.node.destroy()},.5)):0==e.getWorldManifold().normal.y&&(e.disabled=!0,this.player.jump(),this.player.Die())}else e.getWorldManifold().normal.x>0&&0==e.getWorldManifold().normal.y&&o.tag<4?this.node.scaleX=-1:e.getWorldManifold().normal.x<0&&0==e.getWorldManifold().normal.y&&o.tag<4?this.node.scaleX=1:o.tag>=4&&(e.disabled=!0)},t.prototype.update=function(e){this.node.scaleX<0?this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,0):this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(50,0),(this.isDead||this.player.node.x+800<this.node.x)&&(this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(0,0))},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),__decorate([r(c.Mario)],t.prototype,"player",void 0),t=__decorate([n],t)}(cc.Component);o.default=a,cc._RF.pop()},{"./Mario":"Mario"}],Mario:[function(e,t,o){"use strict";cc._RF.push(t,"fb798+fNmdNx6j1XCOu1VTV","Mario"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.bigMario=null,t.smallMario=null,t.jumpAudio=null,t.DieAudio=null,t.PowerUpAudio=null,t.PowerDownAudio=null,t.levelAudio=null,t.anim=null,t.upDown=!1,t.leftDown=!1,t.rightDown=!1,t.onGround=!1,t.isDead=!1,t.playerSpeed=0,t.continueZERO=0,t.isPower=!1,t.isInvincible=!1,t.score=0,t}return __extends(t,e),t.prototype.onLoad=function(){this.isDead=!1,this.anim=this.getComponent(cc.Animation),cc.systemEvent.on(cc.SystemEvent.EventType.KEY_DOWN,this.onKeyDown,this),cc.systemEvent.on(cc.SystemEvent.EventType.KEY_UP,this.onKeyUp,this)},t.prototype.onKeyDown=function(e){cc.log("Key Down: "+e.keyCode),e.keyCode==cc.macro.KEY.up?this.upDown=!0:e.keyCode==cc.macro.KEY.left?(this.leftDown=!0,this.rightDown=!1):e.keyCode==cc.macro.KEY.right&&(this.leftDown=!1,this.rightDown=!0)},t.prototype.onKeyUp=function(e){e.keyCode==cc.macro.KEY.up?this.upDown=!1:e.keyCode==cc.macro.KEY.left?this.leftDown=!1:e.keyCode==cc.macro.KEY.right&&(this.rightDown=!1)},t.prototype.win=function(){cc.audioEngine.playMusic(this.levelAudio,!1),cc.director.loadScene("gameWin")},t.prototype.powerUp=function(){this.isPower=!0,this.node.scale=1.5,this.node.getComponent(cc.Sprite).spriteFrame=this.bigMario},t.prototype.Die=function(){cc.log("Player Die"),this.isInvincible||(this.isInvincible=!0,this.isPower?(this.isPower=!1,cc.audioEngine.playMusic(this.PowerDownAudio,!1),this.node.getComponent(cc.Sprite).spriteFrame=this.smallMario,this.node.scale=1):(cc.audioEngine.playMusic(this.DieAudio,!1),this.isDead=!0,this.anim.play("die"),this.scheduleOnce(function(){cc.director.loadScene("gameOver")},2)),this.scheduleOnce(function(){this.isInvincible=!1},3))},t.prototype.onBeginContact=function(e,t,o){this.isDead?e.disabled=!0:(cc.log(o.tag),0==o.tag?(cc.log("Player hits the ground"),0==e.getWorldManifold().normal.x&&-1==e.getWorldManifold().normal.y&&(this.onGround=!0)):1==o.tag?(cc.log("Player hits the block"),0==e.getWorldManifold().normal.x&&-1==e.getWorldManifold().normal.y&&(this.onGround=!0)):3==o.tag?(cc.log("Player hits the platform"),cc.log(e.getWorldManifold().normal.x,e.getWorldManifold().normal.y),0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y<=-.9?this.onGround=!0:e.disabled=!0):4==o.tag?cc.log("Player hits the goomba"):5==o.tag?cc.log("Player hits the turtle"):7==o.tag?(cc.log("Player hits the mushroom"),cc.audioEngine.playMusic(this.PowerUpAudio,!1),this.score+=1e3,this.isPower||this.powerUp()):8==o.tag&&(cc.log("Player hits the flag"),this.win()))},t.prototype.playerMovement=function(e){this.playerSpeed=0,this.leftDown?(this.playerSpeed=-100,this.node.scaleX=-1):this.rightDown&&(this.playerSpeed=100,this.node.scaleX=1),0!=this.playerSpeed&&(this.isPower?this.anim.getAnimationState("big_run").isPlaying||this.anim.getAnimationState("big_jump").isPlaying||this.anim.play("big_run"):this.anim.getAnimationState("small_run").isPlaying||this.anim.getAnimationState("small_jump").isPlaying||this.anim.play("small_run")),this.node.x+=this.playerSpeed*e,this.upDown&&this.onGround&&(this.continueZERO=0,this.jump())},t.prototype.jump=function(){this.onGround=!1,cc.audioEngine.playMusic(this.jumpAudio,!1),this.isPower?this.anim.getAnimationState("big_run").isPlaying||this.anim.getAnimationState("big_jump").isPlaying||this.anim.play("big_jump"):this.anim.getAnimationState("small_run").isPlaying||this.anim.getAnimationState("small_jump").isPlaying||this.anim.play("small_jump"),this.getComponent(cc.RigidBody).linearVelocity=cc.v2(this.getComponent(cc.RigidBody).linearVelocity.x,500)},t.prototype.update=function(e){this.isDead||(this.playerMovement(e),0==this.getComponent(cc.RigidBody).linearVelocity.y&&(this.continueZERO+=1,this.continueZERO>=10&&(this.onGround=!0)),this.node.y<=-300&&(this.isPower=!1,this.Die()))},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r()],t.prototype,"text",void 0),__decorate([r(cc.SpriteFrame)],t.prototype,"bigMario",void 0),__decorate([r(cc.SpriteFrame)],t.prototype,"smallMario",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"jumpAudio",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"DieAudio",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"PowerUpAudio",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"PowerDownAudio",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"levelAudio",void 0),t=__decorate([n],t)}(cc.Component);o.Mario=c,cc._RF.pop()},{}],Menu:[function(e,t,o){"use strict";cc._RF.push(t,"1700bw7OS1DxKx+bEwryx6m","Menu"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t}return __extends(t,e),t.prototype.selectMode=function(){this.node.getChildByName("Start").active=!1,this.node.getChildByName("Title").active=!1,this.node.getChildByName("STAGE1").active=!0,this.node.getChildByName("STAGE2").active=!0},t.prototype.startGame1=function(e,t){cc.sys.localStorage.setItem("world",t),cc.director.loadScene("gameStart")},t.prototype.onLoad=function(){},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r()],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],MoveObject:[function(e,t,o){"use strict";cc._RF.push(t,"5330b3E1wZD77BUbs1VzFJx","MoveObject"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.moveDirection=!1,t}return __extends(t,e),t.prototype.start=function(){this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,0),this.node.scaleX=-1},t.prototype.onBeginContact=function(e,t,o){e.getWorldManifold().normal.x>0&&0==e.getWorldManifold().normal.y?this.node.scaleX=-1:e.getWorldManifold().normal.x<0&&0==e.getWorldManifold().normal.y&&(this.node.scaleX=1)},t.prototype.update=function(e){this.node.scaleX<1?this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,this.node.getComponent(cc.RigidBody).linearVelocity.y):this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(50,this.node.getComponent(cc.RigidBody).linearVelocity.y)},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],TurtleShell:[function(e,t,o){"use strict";cc._RF.push(t,"af80fUInuhEv4MbAtx79AAS","TurtleShell"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=e("./Mario"),a=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.player=null,t.shell=null,t.moveDirection=!1,t.Speed=0,t.state=0,t.anim=null,t.isDead=!1,t}return __extends(t,e),t.prototype.start=function(){this.anim=this.getComponent(cc.Animation),this.Speed=-30,this.node.scaleX=1,this.state=0},t.prototype.onBeginContact=function(e,t,o){this.player.isDead||(10==o.tag&&(this.player.isInvincible||this.player.jump()),0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y>=.9&&10==o.tag?0==this.state?(this.state=1,this.anim.play("Turtle"),this.Speed=0,this.player.score+=100,this.getComponent(cc.Sprite).spriteFrame=this.shell):0==this.Speed?this.Speed=100:this.Speed=0:0!=this.Speed&&o.tag>=4?10==o.tag?(e.disabled=!0,this.player.isInvincible||this.player.Die()):1==this.state?o.node.destroy():e.disabled=!0:e.getWorldManifold().normal.x>0&&0==e.getWorldManifold().normal.y&&(o.tag<4||10==o.tag)?(this.node.scaleX=1,0==this.state?this.Speed=-30:this.Speed=-100):e.getWorldManifold().normal.x<0&&0==e.getWorldManifold().normal.y&&(o.tag<4||10==o.tag)?(this.node.scaleX=-1,0==this.state?this.Speed=30:this.Speed=100):o.tag>=4&&(e.disabled=!0))},t.prototype.update=function(e){this.player.node.x+800>=this.node.x&&(this.node.x+=this.Speed*e)},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),__decorate([r(c.Mario)],t.prototype,"player",void 0),__decorate([r(cc.SpriteFrame)],t.prototype,"shell",void 0),t=__decorate([n],t)}(cc.Component);o.default=a,cc._RF.pop()},{"./Mario":"Mario"}],camera:[function(e,t,o){"use strict";cc._RF.push(t,"b3014NS8X1DEpwo0zbjHhLE","camera"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=e("./Mario"),a=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.player=null,t.text="hello",t.score=0,t.CLOCK=0,t}return __extends(t,e),t.prototype.onLoad=function(){this.StartTime=(new Date).getTime()},t.prototype.update=function(e){this.node.x=Math.min(1760,Math.max(0,cc.find("Canvas/Mario").x+180));var t=cc.find("Canvas/Main Camera/time"),o=cc.find("Canvas/Main Camera/score");if(this.CLOCK%30==0){o.getComponent(cc.Label).string=""+this.player.score;var i=Math.ceil(((new Date).getTime()-this.StartTime)/1e3);t.getComponent(cc.Label).string=300-i,i>=300&&(this.player.isPower=!1,this.player.Die())}this.CLOCK+=1},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r(c.Mario)],t.prototype,"player",void 0),__decorate([r()],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=a,cc._RF.pop()},{"./Mario":"Mario"}],gameWin:[function(e,t,o){"use strict";cc._RF.push(t,"efea64YmcZCl6vtVAA8rsAD","gameWin"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t}return __extends(t,e),t.prototype.onLoad=function(){this.scheduleOnce(function(){cc.director.loadScene("main")},2)},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r()],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],map1:[function(e,t,o){"use strict";cc._RF.push(t,"a81aeawfb9DyoO9tNMyDI8U","map1"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t}return __extends(t,e),t.prototype.onLoad=function(){cc.director.getPhysicsManager().enabled=!0},t.prototype.update=function(){},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r()],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],mushroom:[function(e,t,o){"use strict";cc._RF.push(t,"69f71r788BHUKWwi7fmSnZs","mushroom"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.moveDirection=!1,t}return __extends(t,e),t.prototype.start=function(){this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,0),this.node.scaleX=-1},t.prototype.onBeginContact=function(e,t,o){o.tag>=4?this.node.destroy():e.getWorldManifold().normal.x>0&&0==e.getWorldManifold().normal.y?this.node.scaleX=-1:e.getWorldManifold().normal.x<0&&0==e.getWorldManifold().normal.y&&(this.node.scaleX=1)},t.prototype.update=function(e){this.node.scaleX<1?this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,this.node.getComponent(cc.RigidBody).linearVelocity.y):this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(50,this.node.getComponent(cc.RigidBody).linearVelocity.y)},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],question1:[function(e,t,o){"use strict";cc._RF.push(t,"5d0e7MaT5BDTZYydJqSJKvF","question1"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=e("./Mario"),a=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.money=null,t.state=0,t.player=null,t.coinAudio=null,t}return __extends(t,e),t.prototype.start=function(){},t.prototype.onBeginContact=function(e,t,o){if(10==o.tag&&0==this.state&&!this.player.isDead&&(cc.log(e.getWorldManifold().normal.x,e.getWorldManifold().normal.y),0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y<.9)){this.state=1,cc.audioEngine.playMusic(this.coinAudio,!1),this.node.getComponent(cc.Sprite).spriteFrame=this.money,this.player.score+=200;var i=cc.spawn(cc.moveBy(.3,0,25),cc.fadeOut(.3));this.node.runAction(i),this.scheduleOnce(function(){this.node.destroy()},.3)}},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),__decorate([r(cc.SpriteFrame)],t.prototype,"money",void 0),__decorate([r(c.Mario)],t.prototype,"player",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"coinAudio",void 0),t=__decorate([n],t)}(cc.Component);o.default=a,cc._RF.pop()},{"./Mario":"Mario"}],question2:[function(e,t,o){"use strict";cc._RF.push(t,"cfedeGFN7hGu7344A1CPnNQ","question2"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=e("./Mario"),a=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.mushroomPrefab=null,t.player=null,t.mushroomAudio=null,t.state=0,t}return __extends(t,e),t.prototype.start=function(){},t.prototype.onBeginContact=function(e,t,o){if(10==o.tag&&0==this.state&&!this.player.isDead&&(cc.log(e.getWorldManifold().normal.x,e.getWorldManifold().normal.y),0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y<.9)){this.state=1,cc.audioEngine.playMusic(this.mushroomAudio,!1);var i=cc.instantiate(this.mushroomPrefab);i.parent=cc.find("Canvas"),i.setPosition(this.node.x,this.node.y+5),this.scheduleOnce(function(){this.node.destroy()},.3)}},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),__decorate([r(cc.Prefab)],t.prototype,"mushroomPrefab",void 0),__decorate([r(c.Mario)],t.prototype,"player",void 0),__decorate([r({type:cc.AudioClip})],t.prototype,"mushroomAudio",void 0),t=__decorate([n],t)}(cc.Component);o.default=a,cc._RF.pop()},{"./Mario":"Mario"}],startGame:[function(e,t,o){"use strict";cc._RF.push(t,"31d27ni4wpBjYYZggNPvirr","startGame"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t}return __extends(t,e),t.prototype.onLoad=function(){this.scheduleOnce(function(){var e=cc.sys.localStorage.getItem("world");cc.log("TEST:",e),cc.director.loadScene("map"+e)},2)},t.prototype.onStart=function(){},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r()],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],startOver:[function(e,t,o){"use strict";cc._RF.push(t,"9031c/YF2dD+LDo66kphoTN","startOver"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t}return __extends(t,e),t.prototype.onLoad=function(){this.scheduleOnce(function(){var e=cc.sys.localStorage.getItem("world");cc.log("TEST:",e),cc.director.loadScene("map"+e)},2)},t.prototype.onStart=function(){},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r()],t.prototype,"text",void 0),t=__decorate([n],t)}(cc.Component);o.default=c,cc._RF.pop()},{}],turtle:[function(e,t,o){"use strict";cc._RF.push(t,"0840eY36YRO3oDGdNcAlWIc","turtle"),Object.defineProperty(o,"__esModule",{value:!0});var i=cc._decorator,n=i.ccclass,r=i.property,c=e("./Mario"),a=function(e){function t(){var t=null!==e&&e.apply(this,arguments)||this;return t.label=null,t.text="hello",t.player=null,t.turtleShell=null,t.moveDirection=!1,t}return __extends(t,e),t.prototype.start=function(){this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,0),this.node.scaleX=1},t.prototype.onBeginContact=function(e,t,o){if(e.getWorldManifold().normal.x>0&&0==e.getWorldManifold().normal.y?this.node.scaleX=1:e.getWorldManifold().normal.x<0&&0==e.getWorldManifold().normal.y&&(this.node.scaleX=-1),"Mario"==o.node.name)if(0==e.getWorldManifold().normal.x&&e.getWorldManifold().normal.y>=.9){cc.log(this.turtleShell);var i=cc.instantiate(this.turtleShell);i.parent=cc.find("Canvas"),i.setPosition(this.node.x,this.node.y),this.player.jump(),this.node.destroy()}else 0==e.getWorldManifold().normal.y&&this.player.Die()},t.prototype.update=function(e){this.node.scaleX>0?this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(-50,0):this.node.getComponent(cc.RigidBody).linearVelocity=cc.v2(50,0)},__decorate([r(cc.Label)],t.prototype,"label",void 0),__decorate([r],t.prototype,"text",void 0),__decorate([r(c.Mario)],t.prototype,"player",void 0),__decorate([r(cc.Prefab)],t.prototype,"turtleShell",void 0),t=__decorate([n],t)}(cc.Component);o.default=a,cc._RF.pop()},{"./Mario":"Mario"}]},{},["Goomba","Mario","Menu","MoveObject","TurtleShell","camera","gameWin","map1","mushroom","question1","question2","startGame","startOver","turtle"]);